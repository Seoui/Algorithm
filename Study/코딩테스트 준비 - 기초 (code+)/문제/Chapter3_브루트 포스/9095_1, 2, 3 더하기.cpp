#include <iostream>
using namespace std;

int d[11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	system("pause");
	return 0;
}

// 백준 - 브루트 포스
/*
#include <iostream>
using namespace std;

int go(int sum, int goal)
{
	if (sum > goal) return 0;
	if (sum == goal) return 1;

	int now = 0;
	for (int i = 1; i <= 3; ++i)
		now += go(sum + i, goal);

	return now;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << go(0, n) << '\n';
	}
	return 0;
}*/

// 서의
/*
int DP[15];

int 방법의수(int n)
{
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;
	for (int i = 4; i <= n; ++i)
		DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];

	return DP[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << 방법의수(n) << '\n';
		fill(DP, DP + 15, 0);
	}
	return 0;
}*/

