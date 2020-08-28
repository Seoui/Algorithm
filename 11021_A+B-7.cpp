#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c, a, b;
	int i = 1;
	cin >> c;

	while (c--)
	{
		cin >> a >> b;
		cout << "Case #" << i++ << ": " << a + b << "\n";
	}

	return 0;
}