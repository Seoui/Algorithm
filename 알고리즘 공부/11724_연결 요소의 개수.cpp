#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[1001];
bool vis[1001];

void bfs(int start) 
{
	queue<int> q;
	vis[start] = true;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); ++i) {
			int nxt = adj[cur][i];
			if (vis[nxt] == false) {
				q.push(nxt);
				vis[nxt] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	// N: 정점의 개수
	// M: 간선의 개수
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ret = 0;
	for(int i =1; i <= N; ++i) {
		if(vis[i] == false) {
			bfs(i);
			ret++;
		}
	}

	cout << ret;
	system("pause");
	return 0;
}