#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

string board[1001];
int dist1[1001][1001]; // ���� ���� �ð�
int dist2[1001][1001]; // �������� �̵� �ð�
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
				dist1[i][j] = 0;	// ���� �Ÿ� 0
			}
			if (board[i][j] == 'J') {
				q2.push({ i, j });
				dist2[i][j] = 0;	// ���� �Ÿ� 0
			}
		}
	}

	// �ҿ� ���� BFS
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

	// �����̿� ���� BFS
	while (!q2.empty()) {
		auto cur = q2.front(); q2.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			// �����ڸ��� ��� ����� ������ ����
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
				cout << dist2[cur.first][cur.second] + 1;
				system("pause");
				return 0;
			}
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			// ���� ������ ���̰�
			// ���� �������� �� �ð��� �����̰� �������� �� �ð��� ������ ��
			// �����̰� �� ũ�ų� ���ٴ� ���� ���̶� ���ÿ� �����ϰų� �̹� �ʾ��ٴ� ���̹Ƿ�
			// �����̴� ������ ����. ���� �׳� continue
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1) continue;
			// ��� if ������ ����� ���� �� �����̸鼭, ���� �� �ʴ� ����
			// �� �����̰� ������ �� �ִ� �����̴�
			dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
			q2.push({ nx, ny });
		}
	}
	// �������� BFS�� ���������� ���� �����ڸ��� ����Ҵٴ� ���̹Ƿ� �Ұ���
	cout << "IMPOSSIBLE" << '\n';
	system("pause");
	return 0;
}