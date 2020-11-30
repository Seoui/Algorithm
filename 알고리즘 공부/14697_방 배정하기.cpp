#include <iostream>
using namespace std;

bool canAllocate(int a, int b, int c, int n)
{
	for (int i = 0; i <= n / a; ++i) {
		for (int j = 0; j <= n / b; ++j) {
			for (int k = 0; k <= n / c; ++k) {
				if (n == a * i + b * j + c * k)
					return true;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int A, B, C, N;
	cin >> A >> B >> C >> N;
	cout << canAllocate(A, B, C, N) << '\n';
	return 0;
}