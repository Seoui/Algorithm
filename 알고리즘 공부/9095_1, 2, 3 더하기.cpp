#include <iostream>
using namespace std;

int DP[15];

int 规过狼荐(int n)
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
		cout << 规过狼荐(n) << '\n';
		fill(DP, DP + 15, 0);
	}
	return 0;
}