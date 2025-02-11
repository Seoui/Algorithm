#include <iostream>
using namespace std;

int dp[100001];
bool state[100000];
int ButtonState(int n, int m)
{
	/*
		동작 1) 모든 버튼을 다 누른다.
		동작 2) 짝수 버튼만 다 누른다.
		동작 3) 홀수 버튼만 다 누른다.
		동작 4) 1, 4, 7, ... , 3k + 1번 버튼만 다 누른다.
		동작 5) 모두 꺼진 상태
	*/

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(dp, -1, sizeof(int) * 100001);
	int N, m; // 누를수있는버튼N[1, 100000], 주어진 시간m[1, 100000]
	cin >> N >> m;
	cout << ButtonState(N, m) << '\n';
	system("pause");
	return 0;
}