#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int C, Q = 0, D = 0, N = 0, P = 0;
		int remainder = 0;
		cin >> C;
		Q = C / 25;
		remainder = C % 25;
		D = remainder / 10;
		remainder %= 10;
		N = remainder / 5;
		remainder %= 5;
		P = remainder / 1;
		remainder %= 1;
		cout << Q << ' ' << D << ' ' << N << ' ' << P << '\n';
	}
	return 0;
}