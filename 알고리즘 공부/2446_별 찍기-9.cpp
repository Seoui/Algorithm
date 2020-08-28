#include <iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;
	int b = 2 * a - 1;

	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			if ((i > j && i + j <= 2 * a - 1) || i + j >= 2 * a - 1)
				cout << " ";
			else
				cout << "*";
		}
		b--;
		cout << '\n';
	}

	for (int i = 0; i < a - 1; ++i)
	{
		b++;
		for (int j = 0; j <= b; ++j)
		{
			if (i + j <= a - 3 || (j - i >= a + 1))
				cout << " ";
			else
				cout << "*";
		}
		cout << '\n';
	}
	return 0;
}