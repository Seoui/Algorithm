#include <iostream>
#include <vector>
using namespace std;

vector<int> dp(1000000, 0);
int NumOfOper(int n)
{
	dp[1] = 0, dp[2] = 1, dp[3] = 1;
	for (int i = 4; i <= n; ++i) {
		if ((i % 3 == 0) && (dp[i - 1] > dp[i / 3]))
			dp[i] = dp[i / 3] + 1;
		else if ((i % 2 == 0) && (dp[i - 1] > dp[i / 2]))
			dp[i] = dp[i / 2] + 1;
		else
			dp[i] = dp[i - 1] + 1;
	}
	return dp[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	cout << NumOfOper(N) << '\n';
	return 0;
}