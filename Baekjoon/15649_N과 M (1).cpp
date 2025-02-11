#include <iostream>
using namespace std;

int N, M;
int arr[10];
bool isused[10];

void func(int k)
{
	if (k == M) {
		for (int i = 0; i < M; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; ++i) {
		if (!isused[i]) {
			arr[k] = i;
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M;
	func(0);
	system("pause");
	return 0;
}