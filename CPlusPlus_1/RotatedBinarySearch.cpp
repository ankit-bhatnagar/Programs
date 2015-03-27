#include <iostream>

using namespace std;

#if 0
int RotatedBinarySearch(int * array, int length, int low, int high, int find) {
	int mid = (low + high)/2;

	/* If left is sorted and fall in that */
	if (array[mid] == find)
		return mid;
	else if (find > array[low] && find < array[low] || find < array[low] && find > array[mid]) {
		return RotatedBinarySearch(array, length, low, mid - 1, find);
	} else if (find > array[mid] && find < array[high] || find < array[mid] && find > array[high]) {
		return RotatedBinarySearch(array, length, mid + 1, high, find);
	}
}
#endif

#if 0
int BinarySearch(int * array, int low, int high, int find) {
	int mid = (low + high)/2;

	if (array[mid] == find)
		return mid;
	else if (find < array[mid])
		return BinarySearch(array, low, mid - 1, find);
	else if (find > array[mid])
		return BinarySearch(array, mid + 1, high, find);
	else
		return -1;
}

int RotatedBinarySearch(int * array, int low, int high, int find) {
	int mid = (low + high)/2;

	if (array[mid] == find)
		return mid;
	else if (find > array[low] && find < array[mid])
		return BinarySearch(array, low, mid - 1, find);
	else if (find > array[mid] && find < array[high])
		return BinarySearch(array, mid + 1, high, find);
	else if (find < array[low] && find > array[mid])
		return RotatedBinarySearch(array, low, mid - 1, find);
	else if (find < array[mid] && find > array[high])
		return RotatedBinarySearch(array, mid + 1, high, find);
	else
		return -1;
}
#endif

#if 1
int BinarySearch(int * array, int low, int high, int find) {
	int mid;

	while (low < high) {
		mid = (low + high)/2;

		if (array[mid] == find)
			return mid;
		else if (array[mid] > find)
			high = mid - 1;
		else if (array[mid] < find)
			low = mid + 1;
	}

	if (low > high)
		return -1;
}

int RotatedBinarySearch(int * array, int low, int high, int find) {
	int mid;

	while (low < high) {
		mid = (low + high)/2;

		if (find == array[mid])
			return mid;
		else if (array[low] < array[mid]) {
			if (find > array[low] && find < array[mid])
				high = mid - 1;
			else
				low = mid + 1;
		} else {
			if (find > array[mid] && find < array[high])
				low = mid + 1;
			else
				high = mid - 1;
		}
	}

	if (low > high)
		return -1;
}
#endif

int main () {
	/* Rotated binary search means doing binary search on rotated array */
	int test[] = {23, 24, 25, 26, 27, 28, 29, 30, 31, 1, 2, 3, 4, 5};
	cout << RotatedBinarySearch(test, 0, 13, 3) << endl;
	int test2[] = {1, 2, 3, 4, 5, 6, 7, 9, 12, 14};
	cout << BinarySearch(test2, 0, 9, 9) << endl;
}