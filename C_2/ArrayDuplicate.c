#include <stdio.h>

void NotSoGood() {
	int array[] = {1,2,3,4,5,6,7,1,9,10,11,12,13};
	int i,j;

	for (i = 0; i < 12; i++) {
		for (j = i + 1; j < 12; j++) {
			if (array[i] == array[j]) {
				goto end;
			}
		}
	}

	end:
	printf("Index = %d", j);
}

int main(int argc, char ** argv) {
	int array[] = {1,2,3,4,5,6,7,1,9,10,11,12,13};
}