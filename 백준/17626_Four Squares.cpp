#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> dp(50001, 0x7f7f7f7f);
int MinNumberOfSquares(int n)
{
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= (int)sqrt(i); j++) {
			dp[i] = min(dp[i], dp[j*j] + dp[i - j * j]);
		}
	}
	return dp[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		if ((int)pow((int)sqrt(i), 2) == i)
			dp[i] = 1;
	}
	cout << MinNumberOfSquares(n) << '\n';
	return 0;
}