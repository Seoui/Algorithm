#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[101];
bool vis[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	int C, P;
	cin >> C >> P;
	while (P--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	queue<int> q;
	q.push(1);
	vis[1] = true;
	int ret = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i];
			if (vis[nxt]) continue;
			q.push(nxt);
			ret++;
			vis[nxt] = true;
		}
	}
	cout << ret;


	system("pause");
	return 0;
}