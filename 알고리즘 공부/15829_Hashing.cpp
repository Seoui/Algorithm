#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long r = 1;
	long long result = 0;
	const int M = 1234567891;
	int L;
	cin >> L;
	while (L--) {
		char alpha;
		cin >> alpha;
		result += ((alpha - 96) * r) % M;
		r = (r * 31) % M;
	}
	result = result % M;
	cout << result << '\n';
	return 0;
}