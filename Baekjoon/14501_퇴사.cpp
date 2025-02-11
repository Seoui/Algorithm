#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<pair<int, int>> TP;
vector<int> dp(16, 0);

int MaxRevenue(int n)
{
	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (i + TP[i].first <= n + 1) {
			dp[i + TP[i].first] = max(dp[i + TP[i].first], dp[i] + TP[i].second);
			result = max(result, dp[i + TP[i].first]);
		}
		dp[i + 1] = max(dp[i + 1], dp[i]);
		result = max(result, dp[i + 1]);
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	TP.push_back(make_pair(0, 0));
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i){
		int T, P;
		cin >> T >> P;
		TP.push_back(make_pair(T, P));
	}
	cout << MaxRevenue(N) << '\n';
	return 0;
}