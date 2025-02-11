// 백준 - Bottom-Up
#include <iostream>
using namespace std;

int d[1000001];

int go(int n)
{
	d[1] = 0;
	for (int i = 2; i <= n; ++i) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && d[i] > d[i / 2] + 1)
			d[i] = d[i / 2] + 1;
		if (i % 3 == 0 && d[i] > d[i / 3] + 1)
			d[i] = d[i / 3] + 1;
	}

	return d[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	cout << go(n) << '\n';
	system("pause");
	return 0;
}

// 백준 - Top-Down
/*
#include <iostream>
using namespace std;

int d[1000001];
int go(int n)
{
	if (n == 1) return 0;
	if (d[n] > 0) return d[n];

	d[n] = go(n - 1) + 1;
	if (n % 2 == 0) {
		int temp = go(n / 2) + 1;
		if (d[n] > temp)
			d[n] = temp;
	}
	if (n % 3 == 0) {
		int temp = go(n / 3) + 1;
		if (d[n] > temp)
			d[n] = temp;
	}
	return d[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	cout << go(n) << '\n';
	system("pause");
	return 0;
}*/

/* 1. 
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
}*/