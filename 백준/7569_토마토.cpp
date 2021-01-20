#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int board[101][101][101];
int days[101][101][101];
int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 0, 1, 0, 0, -1 };
int dz[6] = { 0, 1, 0, 0, -1, 0 };

int M, N, H;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue<tuple<int, int, int>> q;
	cin >> M >> N >> H;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1)
					q.push({ i, j, k });
				else if (board[i][j][k] == 0)
					days[i][j][k] = -1;
			}
		}
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 6; ++dir) {
			int nz = get<0>(cur) + dz[dir];
			int nx = get<1>(cur) + dx[dir];
			int ny = get<2>(cur) + dy[dir];
			if (nx < 0 || nx >= N ||
				ny < 0 || ny >= M ||
				nz < 0 || nz >= H) continue;
			if (board[nz][nx][ny] == -1 || days[nz][nx][ny] >= 0) continue;
			days[nz][nx][ny] = days[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			q.push({ nz, nx, ny });
		}
	}
	int ret = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				if (days[i][j][k] == -1){
					cout << -1;
					return 0;
				}
				ret = max(ret, days[i][j][k]);
			}
		}
	}
	cout << ret << '\n';
	system("pause");
	return 0;
}