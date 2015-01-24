#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void StringCompression (char * inputString, char * outputString) {
	char currChar = *inputString;
	char buff[10];
	int currCount = 0;
	int isSwitch = 1;
	memset(outputString, 0, sizeof(outputString));
	*outputString = '\0';

	while (*inputString) {
		if (currChar == *inputString) {
			currCount++;
		} else {
			/* write to destinaltion */
			strncat(outputString, &currChar, 1);
			itoa(currCount, buff, sizeof(buff));
			strncat(outputString, buff, strlen(buff));
			/* change the curr char */
			currChar = *inputString;
			currCount = 1;
		}
		inputString++;
	}

	/* Add last one */
	strncat(outputString, &currChar, 1);
	itoa(currCount, buff, sizeof(buff));
	strncat(outputString, buff, strlen(buff));

	if (strlen(outputString) > strlen(inputString)) {
		strncpy(outputString, inputString, strlen(inputString));
	}
}

int main (int argc, char ** argv) {
	char * out = (char *)malloc(sizeof(char) * 200);
	StringCompression("aaaabbbbbbbbcccc", out);
	printf("%s\n", out);
}