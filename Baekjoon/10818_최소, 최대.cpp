#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	int cur;
	int max = -1000000;
	int min = 1000000;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> cur;
		if (cur > max) max = cur;
		if (cur < min) min = cur;
	}

	cout << min << " " << max << "\n";

	return 0;
}