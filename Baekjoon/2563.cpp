#include <iostream>
#include <bitset>
#include <array>
using namespace std;

int main()
{
	array<bitset<100>, 100> v;
	int n, sum = 0;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				if (!v[a + i][b + j]) {
					v[a + i][b + j] = true;
					sum++;
				}
			}
		}
	}
	cout << sum << '\n';
	return 0;
}