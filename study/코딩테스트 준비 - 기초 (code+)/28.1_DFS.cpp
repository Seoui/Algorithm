#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getEulerCircuit(int here, vector<int>& circuit)
{
	for (int there = 0; there < adj[here].size(); ++there) {
		while (adj[here][there] > 0)
		{
			adj[here][there]--;
			adj[there][here]--;
			getEulerCircuit(there, circuit);
		}
	}
	circuit.push_back(here);
}
/*
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int here)
{
	cout << here << ' ';
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (visited[there] == 0) // 방문한적 없다면
			dfs(there);
	}
}

void dfsAll()
{
	visited = vector<bool>(adj.size(), false);
	for (int i = 1; i < adj.size(); ++i)
		if (visited[i] == 0)// 방문한적 없다면
			dfs(i);
}

void makeGraph(const vector<string>& words)
{
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	for (int j = 1; j < words.size(); ++j) {
		int i = j - 1;
		int len = min(words[i].size(), words[j].size());
		for (int k = 0; k < len; ++k) {
			if (words[i][k] != words[j][k]) {
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1;
				break;
			}
		}
	}
}
*/
vector<int> seen, order;

void dfs(int here)
{
	seen[here] = 1;
	for (int there = 0; there < adj.size(); ++there)
		if (adj[here][there] && !seen[there])
			dfs(here);
	order.push_back(here);
}
// adj에 주어진 그래프를 위상정렬한 결과를 반환한다.
// 그래프가 DAG가 아니라면 빈 벡터를 반환한다.
vector<int> topologycalSort()
{
	int m = adj.size();
	seen = vector<int>(m, 0);
	order.clear();
	for (int i = 0; i < m; ++i)
		if (!seen[i])
			dfs(i);
	reverse(begin(order), end(order));
	// 만약 그래프가 DAG가 아니라면 정렬 결과에 역방향 간선이 있다.
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
			if (adj[order[j]][order[i]])
				return vector<int>();
	// 없는 경우라면 깊이 우선 탐색에서 얻은 순서를 반환한다.
	return order;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int V, E;
	cin >> V >> E;
	adj.resize(11);
	for(int i = 0; i < E; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfsAll();

	system("pause");
	return 0;
}