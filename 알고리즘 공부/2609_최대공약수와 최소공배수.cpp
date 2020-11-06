#include <iostream>
using namespace std;

void GCDAndLCM(int a, int b)
{
	// GCD: Greatest Common Divisor
	// LCM: Least Common Multiple
	int divisor = 1;
	int gcd = 0;
	int lcm = 0;
	while (true) {
		if (divisor > a || divisor > b) break;
		if ((a % divisor == 0) && (b % divisor == 0))
			gcd = divisor;
		++divisor;
	}
	lcm = a * b / gcd;
	cout << gcd << '\n';
	cout << lcm << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b;
	cin >> a >> b;
	GCDAndLCM(a, b);
	return 0;
}