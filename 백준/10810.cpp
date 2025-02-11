#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M, i, j, k;
	cin >> N >> M;
	vector<int> v(N, 0);
	while (M--) {
		cin >> i >> j >> k;
		for (int x = i - 1; x <= j - 1; ++x) {
			v[x] = k;
		}
	}
	for (auto x : v) {
		cout << x << ' ';
	}
	cout << '\n';
	return 0;
}