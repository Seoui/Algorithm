#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	// ณช
	while (cin >> n) {
		int ret = 1 % n;
		for (int i = 1; i <= n; ++i) {
			if (ret == 0) {
				cout << i << endl;
				break;
			}
			ret = (ret * 10 + 1) % n;
		}
	}
	// น้มุ
	while (cin >> n) {
		int num = 0;
		for (int i = 1;; ++i) {
			num = num * 10 + 1;
			num %= n;
			if (num == 0) {
				cout << i << '\n';
				break;
			}
		}
	}
	system("pause");
	return 0;
}