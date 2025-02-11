#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int vec[10];
int arr[10];

void solution(int k)
{
	if (k == m) {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	int already = -1;

	for (int i = 0; i < n; ++i) {
		if(already != vec[i]){
			already = vec[i];
			arr[k] = vec[i];
			solution(k + 1);
		}
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
	solution(0);
	return 0;
}