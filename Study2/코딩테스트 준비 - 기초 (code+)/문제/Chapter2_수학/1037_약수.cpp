#include <iostream>
#include <limits>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	int min = numeric_limits<int>::max();
	int max = numeric_limits<int>::min();
	while (n--) {
		int divisor;
		cin >> divisor;
		if (divisor < min)
			min = divisor;
		if (divisor > max)
			max = divisor;
	}
	cout << min * max << '\n';
	return 0;
}