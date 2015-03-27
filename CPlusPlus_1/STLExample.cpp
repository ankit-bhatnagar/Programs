#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

void vectorExample() {
	/* vector: Dynamic array of variables, struct or objects. Insert data at the end. */
	vector <string> ss;

	ss.push_back("Hello");
	ss.push_back("How");
	ss.push_back("Do");
	ss.push_back("You");
	ss.push_back("Do");

	cout << "===================vector===================" << endl;

	/* using for loop */
	for (int i = 0; i < ss.size(); i++) {
		cout << ss[i] << endl;
	}

	/* Using iterator */
	for (vector<string>::iterator i = ss.begin(); i != ss.end(); i++) {
		cout << *i << endl;
	}
}

void listExample() {
	/* list: Linked list of variables, struct or objects. Insert/remove anywhere. */
	list <string> l;

	l.push_back("Hi");
	l.push_back("Do");
	l.push_back("You");
	l.push_back("Do");

	// Not in vector
	l.push_front("Hello");

	cout << "===================list===================" << endl;

	/* using for loop */
	// PROBABLY CANT DO
	//for (int i = 0; i < l.size(); i++) {
	//	cout << l[i] << endl;
	//}

	for (list<string>::iterator i = l.begin(); i != l.end(); i++) {
		cout << *i << endl;
	}
}

void mapExample() {
	/* Sparse array example: (why hold space for thousands of elements when all we have is five) */
	map <string, int> weightUs;
	weightUs["Deepak"] = 63;
	weightUs["TusharA"] = 85;
	weightUs["TusharG"] = 70;
	weightUs["Ritesh"] = 60;

	// Another way of inserting
	weightUs.insert (pair<string,int>("SomeGuy",100) );
	weightUs.insert(map<string,int>::value_type("Jonny",50));
	weightUs.insert(make_pair("Manmohan", 80));

	cout << "===================map===================" << endl;

	cout << "Depaks Weight = " << weightUs["Deepak"] << endl;

	for (map<string, int>::iterator i = weightUs.begin(); i != weightUs.end(); i++) {
		cout << (*i).first << " = " << (*i).second << endl;
	}

	map<string, int>::iterator s;
	s = weightUs.find("Suraj");
	//cout << (*s).first << endl; // Will error as not found
	s = weightUs.find("Deepak");
	cout << (*s).first << endl;
}

void queueExample() {
	queue<string> q;
	q.push("Hello");
	q.push("How");
	q.push("Do");
	q.push("You");
	q.push("Do");

	cout << "===================queue===================" << endl;

	while (q.size() != 0) {
		cout << q.front() << endl;
		q.pop();
	}
}

void stackExample() {
	stack<string> q;
	q.push("Hello");
	q.push("How");
	q.push("Do");
	q.push("You");
	q.push("Do");

	cout << "===================stack===================" << endl;

	while (q.size() != 0) {
		cout << q.top() << endl;
		q.pop();
	}
}

int main () {
	/* Call all the examples from here */
	vectorExample();
	listExample();
	mapExample();
	queueExample();
	stackExample();
}