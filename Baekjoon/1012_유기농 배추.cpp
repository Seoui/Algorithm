#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int πË√ﬂπÁ[52][52];
bool vis[52][52];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testCase;
	cin >> testCase;
	while (testCase--) {
		int M, N, K;
		cin >> M >> N >> K;
		for (int i = 0; i < K; ++i) {
			int X, Y;
			cin >> X >> Y;
			πË√ﬂπÁ[X][Y] = 1;
		}
		// M: ∞°∑Œ(x)
		// N: ºº∑Œ(y)
		int πË√ﬂ»Ú¡ˆ∑∑¿Ã = 0;
		for (int x = 0; x < M; ++x) {
			for (int y = 0; y < N; ++y) {
				if (πË√ﬂπÁ[x][y] == 1 && vis[x][y] == 0) {// µÈ∏∞¿˚ æ¯¥¬ πË√ﬂ∫Œ∫–¡˝«’¿Ã∂Û∏È
					// BFS
					queue<pair<int, int>> q;
					q.push({ x, y });
					vis[x][y] = 1;
					πË√ﬂ»Ú¡ˆ∑∑¿Ã++;
					while (!q.empty()) {
						pair<int, int> cur = q.front();
						q.pop();
						for (int dir = 0; dir < 4; ++dir) {
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];
							if (nx < 0 || ny < 0 || ny >= N || nx >= M) continue;
							if (vis[nx][ny] == 1 || πË√ﬂπÁ[nx][ny] == 0) continue;
							q.push({ nx, ny });
							vis[nx][ny] = 1;
						}
					}
				}
			}
		}
		cout << πË√ﬂ»Ú¡ˆ∑∑¿Ã << '\n';
		fill(πË√ﬂπÁ[0], πË√ﬂπÁ[52], 0);
		fill(vis[0], vis[52], 0);
	}
	return 0;
}