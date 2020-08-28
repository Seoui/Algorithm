#include <iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;

	if (a >= 90 && a <= 100)
		cout << "A" << '\n';
	else if (a >= 80 && a <= 89)
		cout << "B" << '\n';
	else if (a >= 70 && a <= 79)
		cout << "C" << '\n';
	else if (a >= 60 && a <= 69)
		cout << "D" << '\n';
	else
		cout << "F" << '\n';
	return 0;
}