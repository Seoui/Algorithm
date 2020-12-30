#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	bool board[502][502] = { 0, };
	bool vis[502][502];
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = { 0, -1, 0, 1 };
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];

	int cnt = 0;
	int maxArea = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			// ���⼭ ���� ������. board�� 1�̰�, �湮���� �ʾҾ�� ��.
			if (board[i][j] == 1 && vis[i][j] != 1) {
				queue<pair<int, int>> q;
				int area = 0;
				++cnt;// ������ ���� �ϳ� �þ
				vis[i][j] = 1;
				q.push({ i, j });
				while(!q.empty()){
					++area;
					pair<int, int> cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; ++dir) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						// ������ ����� ����
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						// ���尡 0�̸� �׸��� �ƴ� ����
						// �̹� �湮�Ǿ��ٸ� ���� ����
						if (board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
						vis[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
				maxArea = max(maxArea, area);
			}
		}
	}

	cout << cnt << '\n' << maxArea << '\n';
	return 0;
}