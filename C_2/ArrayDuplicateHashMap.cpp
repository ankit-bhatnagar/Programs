#include <iostream>
#include <map>

using namespace std;

int main () {
	int array [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 11};
	int i = 0;
	map<int, int> check;

	for (i = 0; i < 11; i++) {
		if (check.find(array[i]) == check.end()) {
			check.insert(pair<int,int>(array[i],1));
		} else {
			cout << "Index" << i << endl;
			break;
		}
	}
}