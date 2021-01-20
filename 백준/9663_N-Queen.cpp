#include <iostream>
using namespace std;
/*
채점번호 23994756 아이디 98shcho
#include <bits/stdc++.h>
using namespace std;
int n;
int visited[15][15];
int dy[8] = { 1,1,1,0,0,-1,-1,-1 };
int dx[8] = { 1,0,-1,1,-1,1,0,-1 };
int ans = 0;
void func(int i,int j,int check) {
	for (int k = i + 1;k < n;++k)
		visited[k][j] += check;
	for (int a = i + 1, b = j + 1;a < n && b < n;++a, ++b)
		visited[a][b] += check;
	for (int a = i + 1, b = j - 1;a < n && b >= 0;++a, --b)
		visited[a][b] += check;
	return;
}

void findPos(int queen,int y) {
	if (queen == 0) {
		++ans;
		return;
	}
	for (int j = 0; j < n; ++j) {
		if (visited[y][j] == 0) {
			func(y, j, 1);
			findPos(queen - 1, y + 1);
			func(y, j, -1);
		}
	}
	return;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	findPos(n, 0);
	cout << ans;
	return 0;
}
*/
bool isused1[40];//열
bool isused2[40];//양의대각
bool isused3[40];//음의대각
int N;
int cnt = 0;
void q(int cur)
{
	// cur는 y이기도 하다. 위에서 아래로 왼쪽에서 오른쪽으로 훑기 때문인데
	// 한 행에 퀸이 있다면 다음 퀸은 적어도 바로 다음 행이다.
	if (cur == N) {
		++cnt;
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (isused1[i] || isused2[i + cur] || isused3[cur - i + N - 1])
			continue;
		isused1[i] = 1;
		isused2[i + cur] = 1;
		isused3[cur - i + N - 1] = 1;
		q(cur + 1);
		isused1[i] = 0;
		isused2[i + cur] = 0;
		isused3[cur - i + N - 1] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	q(0);
	cout << cnt;
	return 0;
}