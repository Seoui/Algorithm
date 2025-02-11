#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <limits>
#include <cmath>
using namespace std;

/*
예제 입력:
	7 14
	0 1 1.3
	0 2 1.1
	0 3 1.24
	3 4 1.17
	3 5 1.24
	3 1 2
	1 2 1.31
	1 2 1.26
	1 4 1.11
	1 5 1.37
	5 4 1.24
	4 6 1.77
	5 6 1.11
	2 6 1.2

예제 출력:
	1.3200000000
*/
vector<pair<int, double>> adj[10001];
int INF = numeric_limits<int>::max();

vector<double> dijkstra(int src)
{
	vector<double> dist(10001, INF);
	dist[src] = 1;
	priority_queue<pair<double, int>> pq;
	pq.push(make_pair(-1, 0));
	while (!pq.empty()) {
		double cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			double nextDist = cost * adj[here][i].second;
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

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		double w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}

	auto ret = dijkstra(0);

	cout << fixed;
	cout.precision(10);
	cout << ret[n - 1];
	
	system("pause");
	return 0;
}