#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int adj[101][101];
int N, M;
int INF = 987654321;

void floyd()
{
	for (int i = 1; i <= N; ++i)
		adj[i][i] = 0;
	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	fill(adj[0], adj[101], INF);
	while (M--) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	floyd();

	int asum = INF;
	int sum = 0;
	int ret = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			sum += adj[i][j];
		if (asum > sum) {
			asum = sum;
			ret = i;
		}
		sum = 0;
	}

	cout << ret;
	system("pause");
	return 0;
}