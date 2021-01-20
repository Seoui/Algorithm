#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, V;
vector<int> graph[1002];
bool visBFS[1002];
bool visDFS[1002];

void BFS()
{
	queue<int> q;
	q.push(V);
	visBFS[V] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (int i = 0; i < graph[cur].size(); ++i) {
			int nxt = graph[cur][i];
			if (visBFS[nxt]) continue;
			q.push(nxt);
			visBFS[nxt] = 1;
		}
	}
}

void DFS()
{
	stack<int> s;
	s.push(V);
	//visDFS[V] = 1;
	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		if (visDFS[cur]) continue;
		visDFS[cur] = 1;
		cout << cur << ' ';
		for (int i = 0; i < graph[cur].size(); ++i) {
			int nxt = graph[cur][graph[cur].size() - 1 - i];
			if (visDFS[nxt]) continue;
			s.push(nxt);
		} 
	}
}

void RecurDFS(int here)
{
	cout << here << ' ';
	visDFS[here] = 1;
	for (int i = 0; i < graph[here].size(); ++i) {
		int there = graph[here][i];
		if (visDFS[there] == 0)
			RecurDFS(there);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// N: 정점의 개수
	// M: 간선의 개수
	// V: 탐색을 시작할 정점의 번호 
	cin >> N >> M >> V;
	for (int i = 0; i < M; ++i) {
		int v, e;
		cin >> v >> e;
		graph[v].push_back(e);
		graph[e].push_back(v);
	}
	for (int i = 1; i <= N; i++)
		sort(begin(graph[i]), end(graph[i]));
	RecurDFS(V);
	cout << '\n';
	BFS();

	return 0;
}