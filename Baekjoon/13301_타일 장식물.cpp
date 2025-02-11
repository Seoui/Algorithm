#include <iostream>
#include <vector>
using namespace std;

vector<long long> dp(81, 0);
long long Perimeter(int n)
{
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 1; i <= n - 2; ++i)
		dp[i + 2] = dp[i + 1] + dp[i];

	return dp[n] * 2 + (dp[n] + dp[n - 1]) * 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	cout << Perimeter(N) << '\n';
	return 0;
}