#include <iostream>
using namespace std;

int main()
{
	int max = 0, r = 0, c = 0;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			int n;
			cin >> n;
			if (max < n) {
				max = n;
				r = i;
				c = j;
			}
		}
	}
	cout << max << '\n' << r + 1 << ' ' << c + 1 << '\n';
	return 0;
}