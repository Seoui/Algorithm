#include <iostream>
using namespace std;

// 내꺼
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

// 백준
int GCD(int a, int b) 
{
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b;
	cin >> a >> b;
	GCDAndLCM(a, b);

	// 백준 코드
	cout << GCD(a, b) << '\n';
	cout << a * b / GCD(a, b) << '\n';
	return 0;
}