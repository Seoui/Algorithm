#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// d[n] = n���� ī�带 �����ϴµ� �����ϴ� �ִ� �ݾ�.
vector<int> d;
vector<int> p;

int go(int n)
{
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			d[i] = max(d[i], d[i - j] + p[j]);
		}
	}
	return d[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	d.resize(n + 1);
	p.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> p[i];
	system("pause");
	return 0;
}