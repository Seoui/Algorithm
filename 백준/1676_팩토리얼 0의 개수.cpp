#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	int cm5 = 0;
	for (int i = 1; i <= N; ++i) {
		if (i % 125 == 0) cm5 += 3;
		else if (i % 25 == 0) cm5 += 2;
		else if (i % 5 == 0) cm5 += 1;
	}
	cout << cm5 << '\n';
	return 0;
}