#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int PermutationString (char * first, char * second) {
	int charCount[256] = {0};

	while (*first) {
		(charCount[(int)*first])++;
		first++; 
	}

	while (*second) {
		/* This was a big mistake to do post -- */
		if (--(charCount[(int)*second]) < 0)
			return 0;
		second++;
	}

	return 1;
}

int main (int argc, char ** argv) {
	printf("%d\n", PermutationString("Deepak", "eepaDk"));
	return 0;
}