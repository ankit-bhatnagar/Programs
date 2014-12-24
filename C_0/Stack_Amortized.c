#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int * STACK_PTR;
int PTR_LENGTH;
int STACK_LENGTH;

/* function to create a stack */
void create_stack()
{
    STACK_PTR = (int *)malloc(sizeof(int));
	STACK_LENGTH = 0;
	PTR_LENGTH = 1;
}

void change_length(int new_length)
{
    int i;
    int * TEMP_PTR = STACK_PTR;
	STACK_PTR = (int *)malloc(new_length * sizeof(int));
	PTR_LENGTH = new_length;
    /* copy time */
	for (i = 0; i < STACK_LENGTH; i++)
	{
	    STACK_PTR[i] = TEMP_PTR[i];
	}
	
	free(TEMP_PTR);
}

void push(int item)
{
	STACK_PTR[STACK_LENGTH++] = item;
	
	/* increase the length and copy also free previous memory */
	printf("[Debug] size ptr = %d \n", PTR_LENGTH);
	
	/* device the better way to ptr_length */
	if (STACK_LENGTH == PTR_LENGTH)
	    change_length(2*STACK_LENGTH);
}

int pop()
{
    if (STACK_LENGTH == PTR_LENGTH/4)
	    change_length(PTR_LENGTH/2);
		
	return STACK_PTR[STACK_LENGTH--];
}

int main(int argc, char *argv[])
{
    int i;

    /* sample client */
	create_stack();
	push(1);
	push(5);
	push(8);
	push(6);
	push(9);
	pop();
	push(0);
	push(0);
	push(0);
	push(0);
	push(0);
	push(0);
	push(0);
	
	for (i = 0; i < STACK_LENGTH; i++)
	{
	    printf("%d \n", STACK_PTR[i]);
	}
	
	return 0;
}