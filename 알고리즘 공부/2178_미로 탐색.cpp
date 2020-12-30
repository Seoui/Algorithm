#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue<pair<int, int>> q;
	string board[102];
	int dist[102][102];
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, 1 };
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> board[i];
	for (int i = 0; i < N; ++i)
		fill(dist[i], dist[i] + M, -1);
	dist[0][0] = 0;
	q.push({ 0, 0 });
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] == '0') continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push({ nx, ny });
		}
	}
	cout << dist[N - 1][M - 1] + 1 << '\n';
	system("pause");
	return 0;
}