#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	// d[i]= i의 약수의 합
	// 모든 d를 구한다.테스트 케이스에 관계없이 변하지 않는 값.
	// 재활용이 가능하다.
	vector<long long> d(MAX + 1, 1);
	for (int i = 2; i <= MAX; ++i) {
		for (int j = 1; i * j <= MAX; ++j) {
			d[i*j] += i;
		}
	}

	// d[i]의 누적합.
	vector<long long> s(MAX + 1);
	for (int i = 1; i <= MAX; ++i)
		s[i] = s[i - 1] + d[i];

	// 각 케이스에 입력 n에 대해서 값 출력
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << s[n] << '\n';
	}
	system("pause");
	return 0;
}