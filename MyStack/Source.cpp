#include <iostream>
#include <string>
#include <fstream>
#include "MyStack.h"
using namespace std;

class User {
	string name;
	string email;
	int age;
	string city;
public:
	User(string name, string email, int age, string city) {
		this->name = name;
		this->email = email;
		this->age = age;
		this->city = city;
	}
	User(){}
	void print() {
		cout << name << "\t(" << email
			<< ",\t" << age << " year,\t"
			<< city << ")" << endl;
	}
	int getAge() {
		return age;
	}
};

int main() {
	MyStack<User> users;
	string p[4];
	fstream file("users.csv", ios::in);
	for (int i = 0; i < 10; i++) {
		getline(file, p[0], ';');
		getline(file, p[1], ';');
		getline(file, p[2], ';');
		getline(file, p[3]);
		users.push(User(p[0], p[1], stoi(p[2]), p[3]));
	}
	file.close();

	while (!users.empty()) {
		if(users.top().getAge()>=18)
			users.top().print();
		users.pop();
	}
}
