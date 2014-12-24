# include<stdio.h>

/* recursive version */
static int factorial(int number)
{
	if (number == 1)
		return 1;
	else
		return number * factorial(number - 1);
}

/* iterative version */
/*
bugs implanted 

- not initialized result
- initialized with 0 while it should be 1
 */
static int factorial_iterative(int number)
{
	int result = 1;
	while (number != 1)
	{
		result = result * number--;
	}

	return result;
}

int main(int argc, char * argv[])
{
	int res = factorial(4);
	printf("Fac 4 = %d", res);
	res = factorial_iterative(4);
	printf("Fac 4 = %d", res);
}