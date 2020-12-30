#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		int ret = a % 10;
		//b = b % 4 + 4;
		for (int i = 1; i < b; ++i)
			ret = (ret * a) % 10;
		if (ret == 0)
			ret = 10;
		cout << ret << '\n';
	}
	return 0;
}