#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ReplaceString(char * inputStr, int strLen) {
	int numSpace = 0;
	char * temp = inputStr;
	char * end = NULL;

	/* count no of spaces first */
	while (temp < inputStr + strLen) {
		if (*temp == ' ')
			numSpace++;
		temp++;
	}

	printf("No of Space = %d\n", numSpace);

	temp = inputStr + strLen - 1;
	end = inputStr + strLen + numSpace * 2 - 1; // for null terminating char
	/* Modify the string */
	while (numSpace != 0) {
		if (*temp == ' ') {
			*end-- = '0';
			*end-- = '2';
			*end-- = '%';
			temp--;
			numSpace--;
		}
		else {
			*end-- = *temp--;
		}
	}
}

int main (int argc, char ** argv) {
	char * str = (char *)malloc(sizeof(char) * 100);
	strncpy(str, "Hello! I would Die                    ", 100);
	ReplaceString(str, 18);
	printf("%s\n", str);
}