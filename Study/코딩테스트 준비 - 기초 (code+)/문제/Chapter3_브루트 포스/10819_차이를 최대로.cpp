#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calc(vector<int>& v)
{
	int ret = 0;
	for (int i = 1; i < v.size(); ++i)
		ret += abs(v[i - 1] - v[i]);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(begin(v), end(v));

	int ret = -1;
	do {
		int c = calc(v);
		ret = ret > c ? ret : c;
	} while (next_permutation(begin(v), end(v)));
	cout << ret;
	system("pause");
	return 0;
}