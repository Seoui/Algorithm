#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// 백준
vector<pair<int, int>> vec;
int n;
int ans = 0;

// day : 현재 일
// sum : 지금까지의 수익의 합
void go(int day, int sum)
{
	// 현재 날짜가 퇴사날이라면 최대 수익 정산
	if (day == n) {
		if (ans < sum) ans = sum;
		return;
	}
	// 만약 현재 날짜가 퇴사날을 초과했다면 바로 return
	if (day > n) return;

	// 상담 하는 경우
	go(day + vec[day].first, sum + vec[day].second);
	// 상담 안하는 경우
	go(day + 1, sum);	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n;
	for(int i = 0; i < n; ++i){
		int t, p;
		cin >> t >> p;
		vec.push_back({ t, p });
	}
	go(0, 0);
	cout << ans;
	system("pause");
	return 0;
}


// 서의
/*
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
}*/