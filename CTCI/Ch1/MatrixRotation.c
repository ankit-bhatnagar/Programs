#include <stdio.h>
#include <stdlib.h>

void PrintMatrix(int * matrix, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d \t", matrix[i * n + j]);
		}
		printf("\n");
	}
}

void RotateMatrix(int * matrix, int n) {
	int layer;
	int i;

	for (layer = 0; layer < n; layer++) {
		int first = layer;
		int last = n - layer - 1;
		for (i = first; i < last; i++) {
			int offset = i - first;
			/*int temp = matrix[first][i];
			matrix[first][i] = matrix[last - offset][first];
			matrix[last - offset][first] = matrix[last][last - offset];
			matrix[last][last - offset] = matrix[i][last];
			matrix[i][last] = temp;*/
			int temp = matrix[first * n + i];
			matrix[first * n + i] = matrix[(last - offset) * n + first];
			matrix[(last - offset) * n + first] = matrix[last * n + (last - offset)];
			matrix[last * n + (last - offset)] = matrix[i * n + last];
			matrix[i * n + last] = temp;
		}
	}
}

int main (int argc, char ** argv) {
	/* test */
	int i, j;
	int * array = (int *)malloc(10 * 10 * sizeof(int));
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			array[i * 10 + j] = i * 10 + j;
		}
	}

	PrintMatrix(array, 10);
	RotateMatrix(array, 10);
	printf("===========================================================================\n\n");
	PrintMatrix(array, 10);
}