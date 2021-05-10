#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	if (N == 1) return 0;
	

	for (int i = 2; i * i <= N; ++i) {
		while (N % i == 0) {
			cout << i << '\n';
			N /= i;
		}
	}

	if (N > 1)
		cout << N << '\n';
	system("pause");
	return 0;
}