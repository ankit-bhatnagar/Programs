#include <iostream>

using namespace std;

int getNext(int n) {
	int c = n;
	int c0 = 0;
	int c1 = 0;

	/* find c0 -> the position of rightmost 1 */
	// Not go in infinite loop
	while (((c & 1) == 0 && (c != 0) {
		c0++;
		c = c >> 1;
	}

	/* find c1 -> the number of 1's before get rightmost non-trailing 0 */
	while ((c & 1) == 1) {
		c1++;
		c = c >> 1;
	}

	if (c0 + c1 == 31 || c0 + c1 == 0) {
		return -1;
	}

	int p = c0 + c1;

	n = n | 1 << p;                      // Flip rightmost non trailing 0
	n = n & ~((1 << p) - 1)              // Clear all bits to the right of p
	n = n | (1 << (c1 - 1) - 1)          // Insert c1 - 1 ones on the right
	return n;
}

int main() {
	cout << getNext(13948) << endl;
}