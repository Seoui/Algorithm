#include <iostream>
using namespace std;

int n, m;
int arr[10];

void solution(int k, int p)
{
	if (k == m) {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = p + 1; i <= n; ++i) {
		arr[k] = i;
		solution(k + 1, i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	solution(0, 0);
	return 0;
}


/*
int n, m;
int arr[10];
bool picked[10];

void solution(int k)
{
	if (k == m) {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (picked[i] == false) {
			if (k > 0 && i < arr[k - 1]) continue;
			arr[k] = i;
			picked[i] = 1;
			solution(k + 1);
			picked[i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	solution(0);
	system("pause");
	return 0;
}*/