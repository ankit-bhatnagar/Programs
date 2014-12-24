#include<stdio.h>
#include<stdlib.h>

/* structure */
typedef struct _list_node
{
	int data;
	struct _list_node * next;
} list_node;

/* Append to a list */
static void append_to_list(list_node ** head, int data)
{
	if (*head == 0)
	{
		/* first entry */
		list_node * temp_node = (list_node*)malloc(sizeof(list_node));
		temp_node->data = data;
		temp_node->next = 0;
		*head = temp_node;
	}
	else
	{
		/* traverse to last and add */
		list_node * temp_node = *head;
		while (temp_node->next != 0)
		{
			temp_node = temp_node->next;
		}

		list_node * new_node = (list_node*)malloc(sizeof(list_node));
		new_node->data = data;
		new_node->next = 0;

		temp_node->next = new_node;
	}
}

/* display */
static void display_list(list_node * head)
{
	list_node * temp_node = head;
	while(temp_node != 0)
	{
		printf("%d ", temp_node->data);
		temp_node = temp_node->next;
	}

	printf("\n");
}

/* nth from last */
static void display_n_from_last(list_node * head, int n)
{
	list_node * temp_node = head;
	list_node * late_move_node = head;
	int index = 0;

	while (temp_node != 0)
	{
		index++;
		temp_node = temp_node->next;
		if (index > n)
		{
			late_move_node = late_move_node->next;
		}
	}

	printf("%d\n", late_move_node->data);
}

/* FOR CYCLE */
/* append with next node given */
static list_node * append_to_list_with_next(list_node ** head, int data, list_node * next)
{
	list_node * new_node;
	if (*head == 0)
	{
		/* first entry */
		new_node = (list_node*)malloc(sizeof(list_node));
		new_node->data = data;
		new_node->next = next;
		*head = new_node;
	}
	else
	{
		/* traverse to last and add */
		list_node * temp_node = *head;
		while (temp_node->next != 0)
		{
			temp_node = temp_node->next;
		}

		new_node = (list_node*)malloc(sizeof(list_node));
		new_node->data = data;
		new_node->next = next;

		temp_node->next = new_node;
	}

	return new_node;
}

/* returns 0 -> no cycle 1 -> cycle */
static int detect_and_display_cycle(list_node * head)
{
	list_node * slow_node = head;
	list_node * fast_node = head;
	int ret_code = 0;

	if (head == 0)
		return ret_code;

	while (fast_node != 0)
	{
		fast_node = fast_node->next;
		fast_node = fast_node->next;
		slow_node = slow_node->next;
		if (fast_node == slow_node)
		{
			ret_code = 1;
			break;
		}
	}

	return ret_code;
}

int main(int argc, char * argv[])
{
	list_node * high_head = 0;
	list_node * high_head_cycle = 0;
	append_to_list(&high_head, 1);
	append_to_list(&high_head, 2);
	append_to_list(&high_head, 3);
	append_to_list(&high_head, 4);
	append_to_list(&high_head, 5);
	append_to_list(&high_head, 6);
	append_to_list(&high_head, 7);
	append_to_list(&high_head, 8);
	append_to_list(&high_head, 9);
	append_to_list(&high_head, 10);
	append_to_list(&high_head, 11);
	append_to_list(&high_head, 12);
	display_list(high_head);
	display_n_from_last(high_head, 4);

	/* CYCLE */
	append_to_list_with_next(&high_head_cycle, 1, 0);
	append_to_list_with_next(&high_head_cycle, 2, 0);
	append_to_list_with_next(&high_head_cycle, 3, 0);
	append_to_list_with_next(&high_head_cycle, 4, 0);
	append_to_list_with_next(&high_head_cycle, 5, 0);
	list_node * temp6 =  append_to_list_with_next(&high_head_cycle, 6, 0);
	append_to_list_with_next(&high_head_cycle, 7, 0);
	append_to_list_with_next(&high_head_cycle, 8, 0);
	append_to_list_with_next(&high_head_cycle, 9, 0);
	append_to_list_with_next(&high_head_cycle, 10, 0);
	append_to_list_with_next(&high_head_cycle, 11, 0);
	append_to_list_with_next(&high_head_cycle, 12, temp6);
	//display_list(high_head_cycle);

	printf("Cycle = %d\n", detect_and_display_cycle(high_head_cycle));
	printf("Cycle = %d\n", detect_and_display_cycle(high_head));
}