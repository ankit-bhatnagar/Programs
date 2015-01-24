#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
	vector<string> names;

	names.push_back("String 1");
	names.push_back("String 2");
	names.push_back("String 3");
	names.push_back("String 4");

	cout << "Loop by index" << endl;

	for (int i = 0 ; i < names.size(); i++) {
		cout << names[i] << endl;
	}

	cout << "Constant Iterator" << endl;

	vector<string>::const_iterator cIterator;
	for (cIterator = names.begin(); cIterator != names.end(); cIterator++) {
		cout << *cIterator << endl;
	}

	cout << "Reverse Iterator" << endl;

	vector<string>::reverse_iterator rIterator;
	for (rIterator = names.rbegin(); rIterator != names.rend(); rIterator++) {
		cout << *rIterator << endl;
	}

	cout << "Something Else" << endl;

	cout << "Size = " << names.size() << endl;
	cout << "First = " << names[0] << endl;

	/* 2D Vector, initialized with 0 */
	vector< vector<int> > twoDimentionVector(3, vector<int>(2, 0));

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << twoDimentionVector[i][j] << endl;
		}
	}
}