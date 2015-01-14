#include <iostream>
#include <string>

using namespace std;

class Hello
{
private:
	string message;
public:
	Hello();
	Hello(string msg);
	void SetMessage(string msg);
	void PrintMessage();
};

Hello::Hello()
{
	message = "Hello World!";
};

Hello::Hello(string msg)
{
	message = msg;
};

void Hello::SetMessage(string msg)
{
	message = msg;
};

void Hello::PrintMessage()
{
	cout << message << endl;
};

int main()
{
	string hello = "Custom Hello World!";
	string helloagain = "Custom Custom Hello World!";
	Hello * h;
	Hello h0;
	Hello h1(hello);
	Hello h2(helloagain);
	h = new Hello();
	h->PrintMessage();
	h0.PrintMessage();
	h1.PrintMessage();
	h2.PrintMessage();
}