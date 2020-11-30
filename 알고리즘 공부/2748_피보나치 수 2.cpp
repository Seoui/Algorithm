#include <iostream>
#include <vector>
using namespace std;

vector<long long> dp(91, 0);
long long Fibonacci(int n)
{
	dp[0] = 0, dp[1] = 1;
	for (int i = 2; i <= n; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];
	return dp[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	cout << Fibonacci(n) << '\n';
	return 0;
}