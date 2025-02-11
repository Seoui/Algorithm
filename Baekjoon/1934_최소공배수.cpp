#include <iostream>
#include <algorithm>
using namespace std;
/*
int GCD(int a, int b)
{
	return a == 0 ? b
		: b == 0 ? a
		: GCD(b, a % b);//<-- 둘다 0이 아닌 경우
}

int LCM(int a, int b)
{
	return (a != 0 && b != 0)
		? a / GCD(a, b) * b : 0;
}
*/

int LCM(int a, int b)
{
	int larger = max(a, b);
	int smaller = min(a, b);
	int r = 0;
	int gcd = 0;
	while(true) {
		r = larger % smaller;
		if (r != 0) {//나머지가 0이 아니면
			larger = smaller;
			smaller = r;
		}
		else {
			gcd = smaller;
			break;
		}
	}
	return a * b / gcd;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int A, B;
		cin >> A >> B;
		cout << LCM(A, B) << '\n';
	}
	return 0;
}