#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

/* Return the position or -1 */
int FindStringPatternBruteForce(char * string, char * pattern) {
	int stringlength = strlen(string);
	int patternlength = strlen(pattern);
	char * s, * p;

	for (int i = 0; i < stringlength - patternlength; i++) {
		s = string + i;
		p = pattern;
		for (int j = i; j < i + patternlength; j++) {
			if (*s != *p) {
				break;
			}
			s++;
			p++;
			if ((p - pattern) == patternlength) {
				return i;
			}
		}
	}
	return -1;
}

int main() {
	/* Test routine */
	char * strp = (char *)malloc(40 * sizeof(char));
	char * pat = (char *)malloc(10 * sizeof(char));
	strcpy(strp, "classiccolaroll");
	strcpy(pat, "cola");
	cout << FindStringPatternBruteForce(strp, pat) << endl;
	cout << FindStringPatternBruteForce(strp, (char *)"cold") << endl;
}