#include <iostream>
using namespace std;

int che[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int M, N;
	cin >> M >> N;
	che[0] = 1; che[1] = 1;
	for (int i = 2; i <= N; ++i) {
		for (int j = 2; i * j < N; ++j) {
			che[i * j] = 1;
		}
	}
	int ret = 0;
	int m = 0;
	bool min = false;
	for (int i = M; i <= N; ++i) {
		if (che[i] == 0) {
			if (!min) {
				m = i;
				min = true;
			}
			ret += i;
		}
	}
	if (ret == 0)
		cout << -1 << '\n';
	else {
		cout << ret << '\n';
		cout << m << '\n';
	}
	system("pause");
	return 0;
}