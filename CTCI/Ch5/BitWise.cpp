#include <iostream>

using namespace std;

#define SETBIT(num, i)     num[i/32] = (num[i/32] | (1 << i%32))
#define ISSET(num, i)      ((num[i/32] & (1 << i%32)) != 0)
#define CLEARBIT(num, i)   num[i/32] = (num[i/32] & ~(1 << i%32))

int main () {
	int bitarray[32] = {0};
	bool i = ISSET(bitarray, 61);
	cout << i << endl;
	SETBIT(bitarray, 61);
	i = ISSET(bitarray, 61);
	cout << i << endl;
}