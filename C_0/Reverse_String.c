#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void reverse_string(char * string)
{
    int i;
    int length = strlen(string);
	int counter = 0;
	char temp;
	int startC = 0;

    /* reverse the complete string first */
    for(i = length - 1; i >= counter; i--, counter++)
    {
		temp = string[i];
		string[i] = string[counter];
		string[counter] = temp;
    }
}

int main(int argc, char * argv[])
{
    char * string;
	string = malloc(100);
    strcpy(string, "the sky is blue");
    reverse_string(string);
	free(string);
	return 0;
}