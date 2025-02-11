#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, i, j;
	cin >> N >> M;
	vector<int> v(N, 0);
	for (int a = 0; a < N; ++a) {
		v[a] = a + 1;
	}

	while (M--) {
		cin >> i >> j;
		swap(v[i - 1], v[j - 1]);
	}

	for (int x : v)
		cout << x << ' ';
	cout << '\n';
	return 0;
}