#include <iostream>
#include <cmath>
using namespace std;

int CalculateVertexCount(int N)
{
	if (N == 0) return 2;
	return CalculateVertexCount(--N) * 2 - 1;
}

int main()
{
	int N;
	cin >> N;
	int r = CalculateVertexCount(N);
	cout << r * r << '\n';
	return 0;
}