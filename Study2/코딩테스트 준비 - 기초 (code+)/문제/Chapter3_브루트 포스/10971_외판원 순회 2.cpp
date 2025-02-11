#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int n;
vector<vector<int>> v;
vector<int> c;

int calc()
{
	int ret = 0;
	for (int i = 1; i < n; ++i) {
		if (v[c[i - 1]][c[i]] == 0)
			return -1;
		ret += v[c[i - 1]][c[i]];
	}
	if (v[c[n - 1]][c[0]] == 0)
		return -1;
	ret += v[c[n - 1]][c[0]];
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	c.resize(n);
	v.resize(n);
	for (int i = 0; i < n; ++i)
		v[i].resize(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];
	for (int i = 0; i < n; ++i)
		c[i] = i;

	int ret = numeric_limits<int>::max();
	do {
		int value = calc();
		if(value != -1)
			ret = ret < value ? ret : value;
	} while (next_permutation(begin(c)+1, end(c)));
	cout << ret << '\n';
	system("pause");
	return 0;
}