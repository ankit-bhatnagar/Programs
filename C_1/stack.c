#include <stdio.h>
#include <stdlib.h>

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
		printf("Stack overflow\n");
		return -1;
	}

	node_t * tempNode = myStack->head;
	int data = tempNode->data;
	myStack->head = myStack->head->next;
	free(tempNode);
	myStack->total_elements--;
	return data;
}

/* 
 * Accepts a postfix expression and evaluates it - currently no parenthesis and only +, -, *, /
 * Error -> returns -1
 */
int PostfixEvaluation(char * inputExpession) {
	stack_t expStack;

	Init(&expStack);
	while (*inputExpession) {
		if (*inputExpession != '+' && *inputExpession != '-' && *inputExpession != '*' && *inputExpession != '/') {
			Push(&expStack, (*inputExpession - '0'));
		} else if (*inputExpession == '+') {
			Push(&expStack, (Pop(&expStack) + Pop(&expStack)));
		} else if (*inputExpession == '-') {
			Push(&expStack, (Pop(&expStack) - Pop(&expStack)));
		} else if (*inputExpession == '*') {
			Push(&expStack, (Pop(&expStack) * Pop(&expStack)));
		} else if (*inputExpession == '/') {
			Push(&expStack, (Pop(&expStack) / Pop(&expStack)));
		} else {
			/* Invalid OP */
		}
		inputExpession++;
	}

	return Pop(&expStack);
}

int main(int argc, char ** argv) {
	stack_t stackOne;
	Init(&stackOne);
	Push(&stackOne, 1);
	Push(&stackOne, 2);
	Push(&stackOne, 3);
	Push(&stackOne, 4);
	printf("%d\n", Pop(&stackOne));
	printf("%d\n", Pop(&stackOne));
	printf("%d\n", Pop(&stackOne));
	printf("%d\n", Pop(&stackOne));
	//printf("%d\n", Pop(&stackOne));

	printf("Expression = %d\n", PostfixEvaluation("234*+"));
}