#include <iostream>
#include <cmath>
#include <numeric>
using namespace std;

double epsilon = numeric_limits<double>::epsilon();

int MinCount(int x, int y)
{
	double N = sqrt(y - x);
	if (N - int(N) > 0.5 || N - int(N) < epsilon)
		return int(2 * round(N) - 1);
	else
		return int(2 * round(N));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		cout << MinCount(x, y) << '\n';
	}
	system("pause");
	return 0;
}