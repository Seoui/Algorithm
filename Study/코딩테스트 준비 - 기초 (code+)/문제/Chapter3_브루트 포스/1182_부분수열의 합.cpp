#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, s;
	cin >> n >> s;
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];

	int ans = 0;
	// 1 << n은 2^n 과 같다. 1,2,4,8,16,... 
	// 조합의 합 공식을 생각하면 전체 조합의 개수를 알 수 있다.
	for (int i = 1; i < (1 << n); ++i) {
		int sum = 0;
		for (int k = 0; k < n; ++k) {
			if (i&(1 << k)) {
				sum += v[k];
			}
		}
		if (sum == s)
			ans += 1;
	}
	cout << ans;
	system("pause");
	return 0;
}