#include <iostream>
using namespace std;

int n, m;
int arr[10];

void solution(int k) 
{
	if (k == m) {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; ++i) {
		arr[k] = i;
		solution(k + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	solution(0);
	return 0;
}