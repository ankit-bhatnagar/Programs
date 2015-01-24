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

/* Queue using stacks */

class MyQueue {
private:
	stack_t * oldStack;
	stack_t * newStack;
	int numberOfElements;
public:
	MyQueue();
	void Enqueue(int data);
	int DeQueue();
};

MyQueue::MyQueue() {
	numberOfElements = 0;
	newStack = (stack_t *)malloc(sizeof(stack_t));
	oldStack = (stack_t *)malloc(sizeof(stack_t));
	Init(newStack);
	Init(oldStack);
}

void MyQueue::Enqueue(int data) {
	if (numberOfElements != 0) {
		if (IsEmptyStack(newStack)) {
			while (!IsEmptyStack(oldStack))
				Push(newStack, Pop(oldStack));
		}
	}
	Push(newStack, data);
	numberOfElements++;
}

int MyQueue::DeQueue() {
	if (numberOfElements != 0) {
		if (IsEmptyStack(oldStack)) {
			while (!IsEmptyStack(newStack))
				Push(oldStack, Pop(newStack));
		}

		numberOfElements--;
		return Pop(oldStack);
	} else {
		/* Queue finish */
	}
}

int main () {
	MyQueue myCoolQueue;
	myCoolQueue.Enqueue(1);
	myCoolQueue.Enqueue(2);
	myCoolQueue.Enqueue(3);
	myCoolQueue.Enqueue(4);
	myCoolQueue.Enqueue(5);
	myCoolQueue.Enqueue(6);
	cout << myCoolQueue.DeQueue() << endl;
	cout << myCoolQueue.DeQueue() << endl;
}