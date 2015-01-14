#include <iostream>
#include <string>

using namespace std;

class Money
{
private:
	int amount_dollars;
	int amount_cents;
public:
	Money():amount_dollars(0), amount_cents(0){};
	Money(int a_dollars, int a_cents);
	void Display_Amount();
	Money operator+ (const Money& param);    /* passing as reference why - somewhat performance and correctness (?) */
};

Money::Money(int a_dollars, int a_cents)
{
	amount_dollars = a_dollars;
	amount_cents = a_cents;
}

void Money::Display_Amount()
{
	cout << "Dollars = " << amount_dollars << "Cents = " << amount_cents << endl;
}

Money Money::operator+(const Money& param)
{
	Money temp;
	temp.amount_dollars = amount_dollars + param.amount_dollars + ((amount_cents + param.amount_cents)/100);
	temp.amount_cents = (amount_cents + param.amount_cents)%100;
	return temp;
}

int main()
{
	Money am1(10, 60);
	Money am2(5, 50);
	Money a_t = am1 + am2;
	a_t.Display_Amount();
}