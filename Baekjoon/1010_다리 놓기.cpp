#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> cache(31, vector<int>(31, -1));
int Combination(int n, int r)
{
	if (n == r || r == 0) return 1;
	int& ret = cache[n][r];
	if (ret != -1) return ret;
	return (ret = Combination(n - 1, r - 1) + Combination(n - 1, r));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		cout << Combination(M, N) << endl;
	}
	return 0;
}