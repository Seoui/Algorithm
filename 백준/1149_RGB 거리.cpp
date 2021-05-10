#include <iostream>
#include <algorithm>
using namespace std;

int dp[3][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		int r, g, b;
		cin >> r >> g >> b;
		dp[0][i] = (dp[1][i - 1] < dp[2][i - 1] ? dp[1][i - 1] : dp[2][i - 1]) + r;
		dp[1][i] = (dp[0][i - 1] < dp[2][i - 1] ? dp[0][i - 1] : dp[2][i - 1]) + g;
		dp[2][i] = (dp[0][i - 1] < dp[1][i - 1] ? dp[0][i - 1] : dp[1][i - 1]) + b;
	}
	cout << min(min(dp[0][N], dp[1][N]), dp[2][N]);
	system("pause");
	return 0;
}
/*
int cost[3][1001];
int cache[3][1001];

int minCost(int color, int n)
{
	if (n == 1)
		return cost[color][n];

	int ret = 0;
	if (color == 0) { //Red
		int gc = 0;
		int bc = 0;

		if (cache[1][n - 1] != 0)
			gc = cache[1][n - 1];
		else
			gc = minCost(1, n - 1);

		if (cache[2][n - 1] != 0)
			bc = cache[2][n - 1];
		else
			bc = minCost(2, n - 1);

		ret = min(gc, bc);
	}
	else if (color == 1) {// Green
		int rc = 0;
		int bc = 0;

		if (cache[0][n - 1] != 0)
			rc = cache[0][n - 1];
		else
			rc = minCost(0, n - 1);

		if (cache[2][n - 1] != 0)
			bc = cache[2][n - 1];
		else
			bc = minCost(2, n - 1);

		ret = min(rc, bc);
	}
	else if (color == 2) {//Blue
		int rc = 0;
		int gc = 0;

		if (cache[0][n - 1] != 0)
			rc = cache[0][n - 1];
		else
			rc = minCost(0, n - 1);

		if (cache[1][n - 1] != 0)
			gc = cache[1][n - 1];
		else
			gc = minCost(1, n - 1);

		ret = min(rc, gc);
	}

	ret += cost[color][n];
	return cache[color][n] = ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for(int i = 1; i <= N; ++i)
		cin >> cost[0][i] >> cost[1][i] >> cost[2][i];
	
	int a = minCost(0, N);
	int b = minCost(1, N);
	int c = minCost(2, N);
	cout << min(min(a, b), c) << endl;
	system("pause");
	return 0;
}*/