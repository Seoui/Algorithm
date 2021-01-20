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

	while (c--)
		cout << i++ << "\n";

	return 0;
}