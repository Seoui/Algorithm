#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

vector<int> d;
vector<int> p;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	d.resize(n + 1);
	p.resize(n + 1);
	fill(begin(d), end(d), numeric_limits<int>::max());

	for (int i = 1; i <= n; ++i)
		cin >> p[i];
	d[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			d[i] = min(d[i], d[i - j] + p[j]);
		}
	}
	cout << d[n];
	system("pause");
	return 0;
}