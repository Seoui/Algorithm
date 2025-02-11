#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, i, j;
	cin >> N >> M;
	vector<int> vec(N);
	for (int a = 0; a < N; ++a)
		vec[a] = a + 1;

	while (M--) {
		cin >> i >> j;
		reverse(vec.begin() + (i - 1), vec.begin() + j);
	}

	for (int x : vec)
		cout << x << ' ';
	cout << '\n';
	return 0;
}