#include <iostream>
using namespace std;
using ll = long long;

ll A, B, C;
ll POWER(ll a, ll b, ll c)
{
	if (b == 1) return a % c;
	ll ret = POWER(a, b / 2, c);
	ret = ret * ret % c;
	if (b % 2 == 0) return ret;
	return ret * a % c;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> A >> B >> C;
	cout << POWER(A, B, C);

	system("pause");
	return 0;
}