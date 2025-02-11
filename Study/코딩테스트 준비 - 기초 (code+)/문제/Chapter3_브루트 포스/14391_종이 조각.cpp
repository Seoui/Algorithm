#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int ans = 0;
	for (int s = 0; s < (1 << n * m); ++s) {
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			int cur = 0;
			for (int j = 0; j < m; ++j) {
				int k = i * m + j;
				if ((s&(1 << k)) == 0) {
					cur = cur * 10 + (v[i][j] - '0');
				}
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}

		for (int j = 0; j < m; ++j) {
			int cur = 0;
			for (int i = 0; i < n; ++i) {
				int k = i * m + j;
				if ((s&(1 << k)) != 0) {
					cur = cur * 10 + (v[i][j] - '0');
				}
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		ans = max(ans, sum);
	}
	cout << ans;
	system("pause");
	return 0;
}