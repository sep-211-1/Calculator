#include <iostream>
using namespace std;

int main() {
	long int n, sum = 0;
	cin >> n;
	if (n > 0)
		for (int i = 1; i < n; i++)
			sum += i;
	else
		for (int i = n; i <= 1; i++)
			sum += i;
	cout << sum;

}