#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

/*
예제 입력:
	1                    // 테스트 케이스임
	8 12 3 2
	1 2 3
	1 6 9
	2 3 6
	3 4 4
	3 5 2
	4 5 7
	6 5 5
	8 6 5
	6 7 3
	8 7 3
	7 5 1
	2 8 3
	2 3 5
	4 6

예제 출력:
	16
*/

// Version 2

vector<pair<int, int>> adj[1002];
vector<int> fire;
int INF = numeric_limits<int>::max();

vector<int> djikstra(int src)
{
	vector<int> dist(1002, INF);
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}

	return dist;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int V, E, n, m;
	cin >> V >> E >> n >> m;
	for (int i = 0; i < E; ++i) {
		int u, v, t;
		cin >> u >> v >> t;
		adj[u].push_back(make_pair(v, t));
		adj[v].push_back(make_pair(u, t));
	}
	for (int i = 0; i < n; ++i) {
		int f;
		cin >> f;
		fire.push_back(f);
	}
	for (int i = 0; i < m; ++i) {
		int s;
		cin >> s;
		adj[1001].push_back(make_pair(s, 0));
	}
	vector<int> dk = djikstra(1001);
	int ret = 0;
	for (int i = 0; i < fire.size(); ++i)
		ret += dk[fire[i]];
	cout << ret;
	system("pause");
	return 0;
}

// Version 1
/*
vector<pair<int, int>> adj[1000];
vector<int> fire;
int INF = numeric_limits<int>::max();

vector<int> djikstra(int src)
{
	vector<int> dist(1000, INF);
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}

	return dist;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<vector<int>> v;
	// V: 장소의 수
	// E: 도로의 수
	// n: 화재 장소의 수
	// m: 소방서 수
	
	int V, E, n, m;
	cin >> V >> E >> n >> m;
	for (int i = 0; i < E; ++i) {
		int u, v, t;
		cin >> u >> v >> t;
		adj[u].push_back(make_pair(v, t));
		adj[v].push_back(make_pair(u, t));
	}
	for (int i = 0; i < n; ++i) {
		int f;
		cin >> f;
		fire.push_back(f);
	}
	for (int i = 0; i < m; ++i) {
		int s;
		cin >> s;
		v.push_back(djikstra(s));
	}

	int ret = 0;
	for (int i = 0; i < fire.size(); ++i) {
		int fm = INF;
		for (int j = 0; j < v.size(); ++j) {
			if (fm > v[j][fire[i]])
				fm = v[j][fire[i]];
		}
		ret += fm;
	}
	cout << ret;
	system("pause");
	return 0;
}*/