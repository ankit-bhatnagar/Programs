#include <iostream>
#include <string>

using namespace std;

class Blame
{
private:
	int intensity;
public:
	Blame(int intensity): intensity(intensity) {};
	void ShowBlame()
	{
		cout << "Blame" << intensity << endl;
	};
	friend void ShowOthersBlame(Blame& param);
};

void ShowOthersBlame(Blame& param)
{
	cout << "Others Blame" << param.intensity << endl;
};

/* Similarly Friend class */

int main()
{
	Blame b1(10);
	Blame b2(100);
	ShowOthersBlame(b2);
}