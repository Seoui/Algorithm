#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<bool> dp(1001, 0);
string Winner(int n)
{
	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	for (int i = 1; i <= n - 3; ++i)
		dp[i + 3] = !(dp[i] & dp[i + 2]);
	return dp[n] ? "SK" : "CY";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	cout << Winner(N) << '\n';
	return 0;
}