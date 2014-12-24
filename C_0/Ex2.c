#include <stdio.h>

static void print_arguments(int argc, char** argv);

static void print_arguments(int argc, char** argv)
{
    int i = 0;
	for (i=0; i<argc; i++)
	{
	    printf("%s\n", argv[i]);
	}
}

int main(int argc, char * argv[])
{
    print_arguments(argc, argv);
    return 0;
}