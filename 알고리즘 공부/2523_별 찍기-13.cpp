#include <iostream>
using namespace std;

int main()
{
	int a;
	int n = 1;
	cin >> a;

	for (int i = 0; i < 2 * a - 1; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << "*";
		}
		cout << '\n';
		if ((2 * a - 1) / 2 <= i)
			n--;
		else
			n++;
	}
	return 0;
}