#include <iostream>
#include <string>

using namespace std;

class Rectangle
{
private:
	int length;
	int width;
public:
	Rectangle() : length(0), width(0) {};
	Rectangle(int length, int width) : length(length), width(width) {};
	Rectangle(Rectangle& param) : length(param.length), width(param.width) {};    /* why pass by ref in copy constructor - to avoid infinite something */
	void Display_Area();
};

void Rectangle::Display_Area()
{
	cout << "Area = " << length * width << endl;
}

int main()
{
	Rectangle r1(10, 5);
	Rectangle r2 = r1;
	r2.Display_Area();
}