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
		// isused 배열은 default로 0이다.
		if (!isused[i]) {
			isused[i] = true;
			arr[k] = i;
			func(k + 1);
			isused[i] = false;
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