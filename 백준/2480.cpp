#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b && b == c) {
		cout << 10000 + a * 1000;
	}
	else if (a != b && a != c && b != c) {
		cout << max(a, max(b, c)) * 100;
	}
	else {
		if (a == b) {
			cout << 1000 + a * 100;
		}
		else if (a == c) {
			cout << 1000 + a * 100;
		}
		else if (b == c) {
			cout << 1000 + b * 100;
		}
	}
	return 0;
}