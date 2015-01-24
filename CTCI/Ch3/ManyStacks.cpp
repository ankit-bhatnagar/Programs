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

/* Many Stacks */
#define MAX_STACK_SIZE        10
#define MAX_STACKS            5

class ManyStacks {
private:
	int currentStackIndex;
	stack_t * stacks;
public:
	ManyStacks ();
	void Push_t(int data);
	int Pop_t();
	int PopAt_t(int index);
};

ManyStacks::ManyStacks() {
	currentStackIndex = 0;
	stacks = (stack_t *)malloc(sizeof(stack_t) * MAX_STACKS);
	for (int i = 0; i < MAX_STACKS; i++) {
		Init(stacks + i);
	}
}

void ManyStacks::Push_t (int data) {
	if (TotalElements(stacks + currentStackIndex) >= MAX_STACK_SIZE) {
		/* Use new Stack */
		currentStackIndex++;
		if (currentStackIndex >= MAX_STACKS) {
			/* Error handling */
			return;
		} else {
			Push(stacks + currentStackIndex, data);
		}
	} else {
		Push(stacks + currentStackIndex, data);
	}
}

int ManyStacks::Pop_t () {
	if (IsEmptyStack(stacks + currentStackIndex)) {
		currentStackIndex--;
		if (currentStackIndex < 0) {
			/* Error handline */
			return NULL;
		} else {
			return Pop(stacks + currentStackIndex);
		}
	} else {
		return Pop(stacks + currentStackIndex);
	}
}

int ManyStacks::PopAt_t(int index) {
	if (index < 0 || index > currentStackIndex) {
		return NULL;
	}

	return Pop(stacks + index);
}

int main () {
	/*  Usage */
	ManyStacks myManyStacks;
	myManyStacks.Push_t(1);
	myManyStacks.Push_t(2);
	myManyStacks.Push_t(3);
	myManyStacks.Push_t(4);
	myManyStacks.Push_t(5);
	myManyStacks.Push_t(6);
	myManyStacks.Push_t(7);
	myManyStacks.Push_t(8);
	myManyStacks.Push_t(9);
	myManyStacks.Push_t(10);
	myManyStacks.Push_t(11);
	myManyStacks.Push_t(12);
	myManyStacks.Push_t(13);
	myManyStacks.Push_t(14);
	myManyStacks.Push_t(15);
	myManyStacks.Push_t(16);
	myManyStacks.Push_t(17);
	myManyStacks.Push_t(18);
	myManyStacks.Push_t(19);
	myManyStacks.Push_t(20);
	myManyStacks.Push_t(21);
	myManyStacks.Push_t(22);
	myManyStacks.Push_t(23);
	myManyStacks.Push_t(24);
	myManyStacks.Push_t(25);
	myManyStacks.Push_t(26);
	cout << myManyStacks.Pop_t() << endl;
	cout << myManyStacks.Pop_t() << endl;
	cout << myManyStacks.PopAt_t(0) << endl;
	cout << myManyStacks.PopAt_t(0) << endl;
}