#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool HasUniqueCharacters(char * inputString) {
	for (int i = 0; i < strlen(inputString); i++) {
		for (int j = i + 1; j < strlen(inputString); j++) {
			if (inputString[i] == inputString[j]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	cout <<  "Rifel" <<HasUniqueCharacters("Rifel") << endl;
	cout <<  "Hello" <<HasUniqueCharacters("Hello") << endl;
	return 0;
}