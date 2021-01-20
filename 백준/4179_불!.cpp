#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

string board[1001];
int dist1[1001][1001]; // 불의 전파 시간
int dist2[1001][1001]; // 지훈이의 이동 시간
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int R, C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		fill(dist1[i], dist1[i] + C, -1);
		fill(dist2[i], dist2[i] + C, -1);
	}

	for (int i = 0; i < R; ++i)
		cin >> board[i];
	
	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (board[i][j] == 'F') {
				q1.push({ i, j });
				dist1[i][j] = 0;	// 시작 거리 0
			}
			if (board[i][j] == 'J') {
				q2.push({ i, j });
				dist2[i][j] = 0;	// 시작 거리 0
			}
		}
	}

	// 불에 대한 BFS
	while (!q1.empty()) {
		auto cur = q1.front(); q1.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
			q1.push({ nx, ny });
		}
	}

	// 지훈이에 대한 BFS
	while (!q2.empty()) {
		auto cur = q2.front(); q2.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			// 가장자리에 닿아 벗어났기 때문에 성공
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
				cout << dist2[cur.first][cur.second] + 1;
				system("pause");
				return 0;
			}
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			// 불이 지나간 곳이고
			// 불이 지나갔을 때 시간과 지훈이가 지나갔을 때 시간을 비교했을 때
			// 지훈이가 더 크거나 같다는 것은 불이랑 동시에 도착하거나 이미 늦었다는 것이므로
			// 지훈이는 그쪽을 못감. 따라서 그냥 continue
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1) continue;
			// 모든 if 조건을 통과한 경우는 빈 공간이면서, 불이 더 늦는 곳임
			// 즉 지훈이가 지나갈 수 있는 공간이다
			dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
			q2.push({ nx, ny });
		}
	}
	// 지훈이의 BFS가 끝나버리면 결코 가장자리에 못닿았다는 뜻이므로 불가능
	cout << "IMPOSSIBLE" << '\n';
	system("pause");
	return 0;
}