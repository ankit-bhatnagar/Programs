#include <iostream>
#include <string>

using namespace std;

template <class T>

class MyPair
{
private:
	T a, b;

public:
	MyPair(T first, T second)
	{
		a = first;
		b = second;
	};
	void DisplayAll();
};

template <class T>

void MyPair<T>::DisplayAll()
{
	cout << a << " and " << b << endl;
}

int main()
{
	MyPair<int> obj1(1, 2);
	obj1.DisplayAll();
	MyPair<double> obj2(1.4, 2.2);
	obj2.DisplayAll();
}