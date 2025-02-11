#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<bool> dp(1001, 0);
string StoneGame(int n)
{
	dp[1] = 0, dp[2] = 1, dp[3] = 0;
	for (int i = 4; i <= n; ++i) {
		dp[i] = !(dp[i - 1] | dp[i - 3]);
	}
	return dp[n] == 1 ? "SK" : "CY";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	cout << StoneGame(N) << '\n';
	return 0;
}