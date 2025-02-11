#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c;
	int i = 1;
	cin >> c;

	for (int i = 0; i < c; ++i)
	{
		for (int j = 0; j <= i; ++j)
			cout << "*";
		cout << "\n";
	}

	return 0;
}