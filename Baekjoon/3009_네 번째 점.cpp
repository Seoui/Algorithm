#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int x[3], y[3];
	for (int i = 0; i < 3; ++i)
		cin >> x[i] >> y[i];

	int rx  = 0, ry = 0;

	if (x[0] == x[1])
		rx = x[2];
	else if (x[0] == x[2])
		rx = x[1];
	else if (x[1] == x[2])
		rx = x[0];

	if (y[0] == y[1])
		ry = y[2];
	else if (y[0] == y[2])
		ry = y[1];
	else if (y[1] == y[2])
		ry = y[0];

	cout << rx << ' ' << ry << '\n';
	system("pause");
	return 0;
}