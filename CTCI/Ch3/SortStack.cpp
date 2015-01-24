#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/* C Style stack */
typedef struct _node_t {
	int data;
	struct _node_t * next;
} node_t;

typedef struct _stack_t {
	node_t * head;
	int total_elements;
} stack_t;

void Init(stack_t * myStack) {
	myStack->head = NULL;
	myStack->total_elements = 0;
}

int Push(stack_t * myStack, int data) {
	node_t * tempNode = (node_t*)malloc(sizeof(node_t));
	if (tempNode == NULL) {
		return -1;
	}

	tempNode->data = data;
	tempNode->next = myStack->head;
	myStack->head = tempNode;
	myStack->total_elements++;
}

int Pop(stack_t * myStack) {
	if (myStack->total_elements == 0) {
		/* stack overflow */
		return -1;
	}

	node_t * tempNode = myStack->head;
	int data = tempNode->data;
	myStack->head = myStack->head->next;
	free(tempNode);
	myStack->total_elements--;
	return data;
}

int IsEmptyStack(stack_t * myStack) {
	if (myStack->total_elements == 0)
		return 1;
	else
		return 0;
}

int TotalElements(stack_t * myStack) {
	return myStack->total_elements;
}

void PopAndDisplayAll(stack_t * myStack) {
	int data;

	while (!IsEmptyStack(myStack)) {
		printf("%d\n", Pop(myStack));
	}
}

int Peek(stack_t * myStack) {
	return myStack->head->data;
}

/* Sort Stack */
void SortStack(stack_t * myStack) {
	stack_t ptempStack;
	stack_t * tempStack = &ptempStack;
	int currElem;

	Init(tempStack);

	while (!IsEmptyStack(myStack)) {
		currElem = Pop(myStack);

		/* Always remember during AND if first is not TRUE second is not evaluated can be used in NULL case i.e. chance of null pointer exception in second */
		while (!IsEmptyStack(tempStack) && (Peek(tempStack) > currElem)) {
			Push(myStack, Pop(tempStack));
		}

		Push(tempStack, currElem);
	}

	PopAndDisplayAll(tempStack);
}

int main () {
	stack_t oneStack;
	Init(&oneStack);
	Push(&oneStack, 1);
	Push(&oneStack, 12);
	Push(&oneStack, 35);
	Push(&oneStack, 94);
	Push(&oneStack, 5);
	Push(&oneStack, 65);
	Push(&oneStack, 72);
	Push(&oneStack, 81);
	SortStack(&oneStack);
}