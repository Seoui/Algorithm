#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> p;
int dp[301][2] = { 0, };

int MaxPoint(int n)
{
	if (n == 1) return p[1];
	dp[1][0] = p[1], dp[1][1] = 0;
	dp[2][0] = p[2], dp[2][1] = p[1] + p[2];
	for (int i = 3; i <= n; ++i) {
		dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + p[i];
		dp[i][1] = dp[i - 1][0] + p[i];
	}
	return max(dp[n][0], dp[n][1]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	p.push_back(0);
	int s;
	cin >> s;
	for (int i = 0; i < s; ++i) {
		int point;
		cin >> point;
		p.push_back(point);
	}
	cout << MaxPoint(s) << '\n';
	system("pause");
	return 0;
}