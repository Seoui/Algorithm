#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	/* 내가 만든
	int n, length = 0;
	cin >> n;
	int tmp = n;
	while (tmp) {
		++length;
		tmp /= 10;
	}
	
	int nine = 9;
	int ret = 0;
	for (int i = 1; i < length; ++i) {
		ret += nine * i;
		nine *= 10;
	}
	n = n - pow(10, length - 1) + 1;
	ret += n * length;
	cout << ret;
	*/

	// 백준
	int n; 
	cin >> n;
	long long ans = 0;
	// len : 숫자자리의 개수
	// n == 356 이면
	/* 
	case 1:
		start = 1
		len = 1
		end = 9
		ans = 9
	case 2:
		start = 10
		len = 2
		end = 99
		ans = 9 + 180 = 189
	case 3:
		start = 100
		len = 3
		end = 999
		end = 356
		ans = 189 + 257 * 3 = 189 + 771 = 960
	*/
	for (int start = 1, len = 1; start <= n; start *= 10, len++) {
		int end = start * 10 - 1;
		if (end > n) {
			end = n;
		}
		ans += (long long)((end - start + 1)*len);
	}
	cout << ans;
	system("pause");
	return 0;
}