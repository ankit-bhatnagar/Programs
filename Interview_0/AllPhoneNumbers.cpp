#include <iostream>

using namespace std;

void swap(int * x, int * y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int PrintAllNumbers(int * array, int len, int index) {
	if (len == index) {
		for (int i = 0; i < len; i++) {
			cout << array[i];
		}
		cout << endl;
	} else {
		for (int j = index; j < len; j++) {
			swap(&array[index], &array[j]);
			PrintAllNumbers(array, len, index + 1);
			swap(&array[index], &array[j]);            //backtrack
		}
	}
}

int main() {
	/* stub to call */
	int inputArray[] = {1, 2, 3, 4};
	PrintAllNumbers(inputArray, 4, 0);
}