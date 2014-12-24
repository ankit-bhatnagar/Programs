#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void print_it(int n, int size, int * array)
{
	if (n < 1)
	{
		int i;
		for ( i = 0; i < size; i++)
		{
			printf("%d", array[i]);
		}
		printf("\n");
	}
	else
	{
		array[n - 1] = 0;
		print_it(n - 1, size, array);
		array[n - 1] = 1;
		print_it(n - 1, size, array);
	}
}

int main (int argc, char * argv[])
{
	int input = 4;

	int * array = (int*)malloc(sizeof(int) * input);
	memset(array, 0, sizeof(array));
	print_it(input, input, array);
	free(array);
}