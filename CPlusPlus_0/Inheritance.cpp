#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
	int limbs;
public:
	Animal();
	Animal(int limbsArgs);
	void Eat(int foodCalories);
};

class Dog: public Animal {
public:
	Dog();
	Dog(int limbsArgs);
	void Bark();
};

/* currently public inheritance, if the inheritance is protected 
all the member of Amimal becomes protected in Cat i.e. they behave 
as protected in cat's Subclass */
class Cat: public Animal {
public:
	Cat();
	Cat(int limbsArgs);
	void Meow();
};

Animal::Animal() {
	cout << "Animal Created" << endl;
}

Animal::Animal(int limbsArgs) {
	limbs = limbsArgs;
	cout << "Animal with limbs created " << limbsArgs << endl;
}

void Animal::Eat(int foodCalories) {
	cout << "Eaten calories = " << foodCalories << endl;
}

Dog::Dog() {
	cout << "Dog Created" << endl;
}

Dog::Dog(int limbsArgs): Animal(limbsArgs) {
	cout << "Dog with limbs created " << limbsArgs << endl;
}

void Dog::Bark() {
	cout << "Dog Barked" << endl;
}

Cat::Cat() {
	cout << "Cat created" << endl;
}

Cat::Cat(int limbsArgs) {
	/* limbs is available to Cat */
	limbs = limbsArgs;
	cout << "Cat with limbs created " << limbs << endl;
}

void Cat::Meow() {
	cout << "Cat Meow" << endl;
}

int main()
{
	/* First the constructor of parent will be called */
	Dog d;
	d.Eat(100);
	d.Bark();

	Dog d1(4);
	d1.Eat(200);
	d1.Bark();

	Cat c(4);
	/* function of base class are available to child */
	c.Eat(400);
}