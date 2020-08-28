#include <iostream>
using namespace std;

int main()
{
	int a, b;
	int result = 0;
	int count = 0;
	cin >> a;
	result = a;
	while (true)
	{
		b = result;
		result = b / 10 + b % 10;
		result = result % 10 + b % 10 * 10;
		count++;
		if (result == a)
			break;
	}
	cout << count << '\n';

	return 0;
}