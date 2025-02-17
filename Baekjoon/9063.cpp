#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
	int max_x = INT_MIN, min_x = INT_MAX, max_y = INT_MIN, min_y = INT_MAX;
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		if (max_x <= x)
			max_x = x;
		if (min_x > x)
			min_x = x;

		if (max_y <= y)
			max_y = y;
		if (min_y > y)
			min_y = y;
	}
	cout << (max_x - min_x) * (max_y - min_y) << '\n';
	return 0;
}