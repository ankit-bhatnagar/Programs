#include <stdio.h>

/* seed value depends what we take */
int fibonacci_recursive(int number)
{
	if (number == 1)
		return 1;
	else if (number == 2)
		return 1;
	else
		return fibonacci_recursive(number - 1) + fibonacci_recursive(number - 2);
}

/*
Bug 
- what about when pass 1, 2, 3, etc
*/

int fibonacci_iterative(int number)
{
	if (number == 1)
		return 1;
	else if (number == 2)
		return 1;

	int i;
	int fib_1 = 1;
	int fib_2 = 1;
	int fib = 0;
	for (i = 3; i <= number; i++)
	{
		fib = fib_1 + fib_2;
		fib_2 = fib_1;
		fib_1 = fib;
	}

	return fib;
}

int main (int argc, char * argv[])
{
	int result = fibonacci_recursive(10);
	printf("Fib 6 = %d\n", result);
	result = fibonacci_iterative(10);
	printf("Fib 6 = %d\n", result);
}