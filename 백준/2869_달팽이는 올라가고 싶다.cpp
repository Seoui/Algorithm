#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;

int GetDays(int A, int B, int V)
{
	if (A == V) return 1;
	double dV = static_cast<double>(V);
	double dA = static_cast<double>(A);
	double dB = static_cast<double>(B);
	int days = static_cast<int>(ceil((dV - dA) / (dA - dB))) + 1;
	return days;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int A, B, V;
	cin >> A >> B >> V;
	cout << GetDays(A, B, V) << '\n';

	/*test
	while (true)
	{
		cin >> A >> B >> V;
		auto start = chrono::system_clock::now();
		int result = GetDays(A, B, V);
		auto end = chrono::system_clock::now();
		cout << result << '\n';
		auto diff = end - start;
		cout << chrono::duration<double, milli>(diff).count() << '\n';
		cout << "------------------------------" << '\n';
	}
	system("pause");
	*/
	return 0;
}