#include <iostream>
using namespace std;

int Z(int N, int r, int c)
{
	if (N == 0) return 0;
	int half = 1 << (N - 1);
	if (r < half && c < half)//1
		return Z(N - 1, r, c);
	else if (r < half && c >= half)
		return half * half + Z(N - 1, r, c - half);
	else if (r >= half && c < half)//3
		return 2 * half * half + Z(N - 1, r - half, c);
	return 3 * half * half + Z(N - 1, r - half, c - half);//4
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, r, c;
	cin >> N >> r >> c;
	cout << Z(N, r, c) << '\n';
	return 0;
}