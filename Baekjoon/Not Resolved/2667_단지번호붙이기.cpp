#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int n;
string num;
int table[26][26];
int visited[26][26];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void dfs()
{
	int danji = 0;
	vector<int> jips;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (table[i][j] == 1 && visited[i][j] != 1) {
				++danji;
				queue<pair<int, int>> q;
				visited[i][j] = 1;
				q.push(make_pair(i, j));
				int jip = 0;
				while (!q.empty()) {
					++jip;
					pair<int, int> cur = q.front();
					q.pop();
					for (int dir = 0; dir < 4; ++dir) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (table[nx][ny] == 0 || visited[nx][ny] == 1) continue;
						visited[nx][ny] = 1;
						q.push(make_pair(nx, ny));
					}
				}
				jips.push_back(jip);
			}
		}
	}
	cout << danji << '\n';
	sort(begin(jips), end(jips));
	for (auto& j : jips)
		cout << j << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		for (int j = 0; j < n; ++j)
			table[i][j] = num[j] - '0';
	}
	dfs();
	system("pause");
	return 0;
}