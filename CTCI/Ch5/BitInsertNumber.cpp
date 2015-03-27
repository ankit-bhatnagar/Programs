#include <iostream>

using namespace std;

void insertAndPrintNumber(int N, int M, int i, int j) {
	/* preparing the mask */
	int allones = ~0;
	int left = allones << (j + 1);
	int right = (1 << i) - 1;    /* This is interesting property of bit operations, 1000 - 1 gives 111 */
	int mask = left | right;
	int cleared_n = N & mask;
	int shifted_m = M << i;
	cout << (cleared_n | shifted_m) << endl;
}

int main() {
	insertAndPrintNumber(546, 23, 2, 4);
}