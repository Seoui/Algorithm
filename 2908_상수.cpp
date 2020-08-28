#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int A, B;
	int rA, rB;
	cin >> A >> B;
	rA = A % 10 * 100 + A % 100 / 10 * 10 + A / 100;
	rB = B % 10 * 100 + B % 100 / 10 * 10 + B / 100;
	if (rA > rB)
		cout << rA << "\n";
	else
		cout << rB << "\n";

	return 0;
}