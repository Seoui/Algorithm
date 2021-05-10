#include <iostream>
using namespace std;

const double pi = 3.14159265358979;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int r;
	cin >> r;
	
	cout << fixed;
	cout.precision(6);
	cout << double(pi * r * r) << endl;
	cout << double(2 * r * r) << endl;
	return 0;
}