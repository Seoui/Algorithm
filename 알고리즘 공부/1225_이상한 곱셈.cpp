#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string A, B;
	cin >> A >> B;
	int sumA = 0;
	int sumB = 0;
	for (int i = 0; i < A.length(); ++i)
		sumA += A[i] - '0';
	for (int i = 0; i < B.length(); ++i)
		sumB += B[i] - '0';
	cout << sumA * sumB;
	return 0;
}