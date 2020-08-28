#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	if (a == 0 && b < 45)
		a = 24;
	cout << (a * 60 + b - 45) / 60 << " " << (a * 60 + b - 45) % 60 << '\n';
	return 0;
}