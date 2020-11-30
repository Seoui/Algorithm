#include <iostream>
using namespace std;

int fibonacci(int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	cout << fibonacci(n) << '\n';
	system("pause");
	return 0;
}