#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		x -= 1;
		y -= 1;
		bool ok = false;
		for (int k = x; k < n*m; k += m) {
			if (k%n == y) {
				cout << k + 1 << '\n';
				ok = true;
				break;
			}
		}
		if (!ok)
			cout << -1 << '\n';
	}
	system("pause");
	return 0;
}