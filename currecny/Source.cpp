#include <iostream>
using namespace std;

class Money {
	double sum;
	string currency;
	static string* currencies;
	static double Translate(string cur1, string cur2, double sum) {
		if (cur1 == "KAZ") {
			if (cur2 == "RUS") return sum * 6;
			else if (cur2 == "KAZ") return sum;
			else return sum * 431;
		}
		else if (cur1 == "RUS") {
			if (cur2 == "RUS") return sum;
			else if (cur2 == "KAZ") return sum / 6;
			else return sum * 75.5;
		}
		else {
			if (cur2 == "RUS") return sum / 75.5;
			else if (cur2 == "KAZ") return sum / 431;
			else return sum;
		}
	}
public:
	Money(double sum = 0, string currency = "KAZ") {
		this->sum = sum;
		this->currency = currency;
	}
	Money operator+(const Money& rv) {
		return Money(this->sum + Translate(this->currency, rv.currency, rv.sum),
			this->currency);
	}
};
string* Money::currencies = new string[]{ "KAZ","RUS","USA" };
