#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c, a, b;
	cin >> c;

	while (c--)
	{
		cin >> a >> b;
		cout << a + b << "\n";
	}

	return 0;
}