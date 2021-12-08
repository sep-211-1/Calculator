#include <iostream>
#include "MyArray.h"
using namespace std;

class User {
	string name;
	int age;
public:
	User(string name, int age) {
		this->name = name;
		this->age = age;
	}
	User(){}
	void print() {
		cout << name << "\t" << age << endl;
	}
	/*bool operator>(const User& rv) {
		return this->name > rv.name;
	}
	bool operator<(const User& rv) {
		return this->name < rv.name;
	}*/
	bool operator>(const User& rv) {
		return this->age > rv.age;
	}
	bool operator<(const User& rv) {
		return this->age < rv.age;
	}
};

int main() {
	MyArray<User>users;
	users.push(User("John", 26));
	users.push(User("Anna", 25));
	users.push(User("Daniel", 27));
	users.sort();
	for (int i = 0; i < users.size(); i++) {
		users[i].print();
	}
}