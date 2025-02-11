#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c;
	cin >> c;

	for (int i = 0; i < c; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (i + j < c - 1)
				cout << " ";
			else
				cout << "*";
		}
		cout << "\n";
	}

	return 0;
}