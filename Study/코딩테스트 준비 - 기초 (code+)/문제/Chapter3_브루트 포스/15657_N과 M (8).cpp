#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int vec[10];
int arr[10];

void solution(int k, int p)
{
	if (k == m) {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = p; i < n; ++i) {
		arr[k] = vec[i];
		solution(k + 1, i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> vec[i];
	sort(vec, vec + n);
	solution(0, 0);
	return 0;
}