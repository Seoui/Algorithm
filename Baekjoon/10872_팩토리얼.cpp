#include <iostream>
using namespace std;

int factorial(int n)
{
	if (n == 1) return 1;
	if (n == 0) return 1;
	return n * factorial(n - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	cout << factorial(N) << '\n';
	return 0;
}