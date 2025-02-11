#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int board[1002][1002];
int days[1002][1002];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int M, N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue<pair<int, int>> q;
	cin >> M >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				q.push({ i, j });
			if (board[i][j] == 0)// 익지않은 토마토인 경우
				days[i][j] = -1;
		}
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (days[nx][ny] >= 0 || board[nx][ny] == -1) continue;
			days[nx][ny] = days[cur.first][cur.second] + 1;
			q.push({ nx, ny });
		}
	}
	
	int ret = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (days[i][j] == -1) {
				cout << -1;
				return 0;
			}
			ret = max(ret, days[i][j]);
		}
	}
	cout << ret << '\n';
	return 0;
}