#include <iostream>
#include <vector>
using namespace std;

vector<int> m(100000, -1);

int MinCount(int a, int b)
{
	if (a == -1 && b != -1) return b;
	else if (a != -1 && b == -1) return a;
	else return a < b ? a : b;
}

int Change(int n)
{
	m[0] = 0, m[1] = -1, m[2] = 1;
	m[3] = -1, m[4] = 2;
	for (int i = 5; i <= n; ++i)
		m[i] = MinCount(m[i - 5], m[i - 2]) + 1;
	return m[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	cout << Change(n) << '\n';
	return 0;
}