#include <iostream>
using namespace std;

void Hanoi(int from, int to, int n)
{
	if (n == 1) {
		cout << from << ' ' << to << '\n';
		return;
	}
	Hanoi(from, 6 - from - to , n - 1);
	cout << from << ' ' << to << '\n';
	Hanoi(6 - from - to, to, n - 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	cout << (1 << N) - 1 << '\n';
	Hanoi(1, 3, N);
	return 0;
}