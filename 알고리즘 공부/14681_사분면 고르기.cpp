#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	if (a > 0 && b > 0)
		cout << 1 << '\n';
	else if (a > 0 && b < 0)
		cout << 4 << '\n';
	else if (a < 0 && b>0)
		cout << 2 << '\n';
	else
		cout << 3 << '\n';
	return 0;
}