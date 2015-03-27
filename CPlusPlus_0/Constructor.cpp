#include <iostream>

using namespace std;

class Animal {
public:
	Animal() {
		cout << "Animal Constructor" << endl;
	}

	Animal(int a) {
		animalId = a;
		cout << "Animal Constructor +" << endl;
	}

	~Animal() {
		cout << "Animal Destructor" << endl;
	}

private:
	int animalId;
};

class Dog: public Animal {
public:
	Dog() : Animal(4) {
		cout << "Dog Constructor" << endl;
	}

	~Dog() {
		cout << "Dog Destructor" << endl;
	}

	void showDog() {
		cout << "Dog is I" << endl;
	}
};

int main () {
	Dog a;
	a.showDog();
}