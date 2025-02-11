#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
예제 입력:
	8 12
	8 6 5 8 3 5 8 4
	1 6 9
	1 2 3
	2 8 3
	6 8 5
	6 7 3
	8 7 3
	6 5 5
	4 5 7
	3 4 4
	3 5 2
	2 3 6
	7 5 1
	2
	1 5
	6 3

예제 출력:
	17
	10
*/
int adj[501][501];
int via[501][501];
vector<int> time;
/* V: 장소의 수
   E: 도로의 수 */
int V, E;

void floyd()
{
	for (int i = 0; i < V; ++i)
		adj[i][i] = 0;
	fill(via[0], via[501], -1);
	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				if (adj[i][j] > adj[i][k] + adj[k][j]) {
					via[i][j] = k;
					adj[i][j] = adj[i][k] + adj[k][j];
				}
}

void reconstruct(int u, int v, vector<int>& path)
{
	if (via[u][v] == -1) {
		path.push_back(u);
		if (u != v)
			path.push_back(v);
	}
	else {
		int w = via[u][v];
		reconstruct(u, w, path);
		path.pop_back();
		reconstruct(w, v, path);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> V >> E;

	for (int i = 0; i < V; ++i) {
		int ti = 0;
		cin >> ti;
		time.push_back(ti);
	}

	for (int i = 0; i < E; ++i) {
		int ai, bi, ci;
		cin >> ai >> bi >> ci;
		adj[ai][bi] = ci;
		adj[bi][ai] = ci;
	}

	floyd();
	/*
	s: 출발 위치
	t: 도착 위치
	*/
	int T;
	cin >> T;
	while (T--) {
		vector<int> path;
		int s, t;
		cin >> s >> t;
		reconstruct(s, t, path);
		cout << adj[s][t] <<'\n';

	}
	system("pause");
	return 0;
}