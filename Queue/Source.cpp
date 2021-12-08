#include <iostream>
#include "MyQueue.h"
#include <Windows.h>
using namespace std;

void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

int main() {
	srand(time(NULL));
	MyQueue<int> nums;
	int coin, counter=0;
	for (int i = 0; i < 10; i++)
		nums.push_back(rand() % 499 + 100);
	while (!nums.empty()) {

		if (nums.front() % 2 == 0) SetColor(10, 0);
		else SetColor(12, 0);

		cout << nums.front()<<"\t"
			<< (nums.front() % 2 == 0 ? "Even" : "Odd")
			<< endl;

		coin = rand() % 2;
		nums.pop_front();
		if (coin == 1)
			nums.push_back(rand() % 999 + 100);
		counter++;
	}
	SetColor(15, 0);
	cout << "Nums count: " << counter << endl;
}

/*nums
10 чисел
while(){
	cout num "Even/odd"
	rand
	if ->push
}
*/