#include <iostream>
using namespace std;

int main()
{
	int X, N, a, b = 0;
	cin >> X >> N;

	int total = 0;
	while (N--) {
		cin >> a >> b;
		total += a * b;
	}

	if (total == X) {
		cout << "Yes" << '\n';
	}
	else {
		cout << "No" << '\n';
	}

	return 0;
}