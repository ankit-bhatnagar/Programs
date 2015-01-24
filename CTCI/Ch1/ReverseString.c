#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ReverseString(char * inputString) {
	char * end = inputString + (strlen(inputString) - 1);
	char temp;
	while (inputString < end) {
		temp = *(inputString);
		*(inputString) = *(end);
		*(end) = temp;
		inputString++;
		end--;
	}
}

int main(int argc, char ** argv) {
	char * str = malloc(sizeof(char) * 20);
	strncpy(str, "DeepakR", 20);
	ReverseString(str);
	printf("%s\n", str);
	return 0;
}