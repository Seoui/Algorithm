#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <queue>
using namespace std;

int V;
int INF = numeric_limits<int>::max();
vector<pair<int, int>> adj[7];

vector<int> dijkstra(int src)
{
	vector<int> dist(V, INF);
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

	V = 7;
	adj[0] = { {1, 5}, {2, 1} };
	adj[1] = { {5, 3}, {6, 3} };
	adj[2] = { {3, 2} };
	adj[3] = { {1, 1}, {4, 5}, {5, 3} };
	adj[5] = { {6, 3} };
	auto ret = dijkstra(0);
	system("pause");
	return 0;
}