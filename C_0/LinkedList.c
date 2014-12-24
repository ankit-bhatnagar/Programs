#include <stdio.h>
#include <stdlib.h>

/*
 * Structure representing Linked List Node
 */

typedef struct _node
{
	int data;
	struct _node *prev;
	struct _node *next;
} node;

/*
 * Function to add to linked list
 */
 
int addToList(node ** _first,node ** _last,int _data)
{
	node * temp;
	
	//If node is root node
	if(*_first == NULL)
	{
		temp = (node*)malloc(sizeof(node));
		
		if(temp == NULL)
		{
			printf("Error: In memory allocation\n");
			return -1;
		}
		temp->prev = NULL;
		temp->data = _data;
		temp->next = NULL;
		
		*_first = temp;
		*_last = temp;
		
		return 0;
	}
	else
	{
		temp = (node*)malloc(sizeof(node));
		
		if(temp == NULL)
		{
			printf("Error: In memory allocation\n");
			return -1;
		}
		
		temp->prev = *_last;
		temp->data = _data;
		temp->next = NULL;
		
		(*_last)->next = temp;
		
		*_last = temp;
		
		return 0;
	}
}

/*
 * Displaying the List
 */

void displayList(node * _first)
{
	while(_first != NULL)
	{
		printf("%d\t",_first->data);
		_first = _first->next;
	}
	printf("\n");
}

/*
 * Deleting an element at nth postion
 */
 
int deleteAt(node ** _first,node ** _last, int n)
{
	int i;
	node * temp;
	
	if(*_first == NULL)
	{
		printf("Error: Empty List cannot delete\n");
		return -1;
	}
	
	if(n == 1)
	{
		// Special case first element
		temp = *_first;
		
		*_first = (*_first)->next;
		(*_first)->prev = NULL;
		
		free(temp);
		
		return 0;
	}
	else
	{
		temp = *_first;
		
		// Traversing to the position while checking for overflow
		for(i = 0; i < n-1; i++)
		{
			temp = temp->next;
			
			if(temp == NULL)
			{
				printf("Error: overflow of list\n");
				return -1;
			}
		}
		
		// Deleting the node
		if(temp->next == NULL)
		{
			// Special case last element
			(temp->prev)->next = NULL;
			*_last = temp->prev;
			
			free(temp);
			
			return 0;
		}
		else
		{
			(temp->prev)->next = temp->next;
			(temp->next)->prev = temp->prev;
			
			free(temp);
			
			return 0;
		}
	}
}

int main()
{
	node * first = NULL;
	node * last = NULL;
	
	addToList(&first,&last,5);
	addToList(&first,&last,45);
	addToList(&first,&last,98);
	addToList(&first,&last,2);
	addToList(&first,&last,0);
	addToList(&first,&last,3);
	addToList(&first,&last,60);
	addToList(&first,&last,67);
	addToList(&first,&last,96);
	
	displayList(first);
	
	deleteAt(&first,&last,2);
	
	displayList(first);
	
	return 0;
}
