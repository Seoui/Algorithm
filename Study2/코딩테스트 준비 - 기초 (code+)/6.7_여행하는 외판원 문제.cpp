#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

int n;					// 도시의 수 [1, 10]
double dist[10][10];	// 도시 사이의 거리, dist[y][x] = y도시와 x도시 사이의 거리

double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength)
{
	if (path.size() == n)
		return currentLength + dist[path[0]][path.back()];	// ?????????????????????????????????뒤에 dist는 왜 더하는걸까
	double ret = numeric_limits<double>::max();
	for (int next = 1; next < n; ++next) {
		// 이미 방문한 도시라면 continue해서 next값을 다음로 넘긴다(++next)
		if (visited[next]) continue;
		int here = path.back();
		path.push_back(next);
		visited[next] = true;
		// 나머지 경로를 재귀로 
		double cand = shortestPath(path, visited, currentLength + dist[here][next]);
		ret = min(ret, cand);
		// 아래 두 줄은 다음 for문을 위해 초기화~!
		// 다시 방문 안한것으로(초기화)
		visited[next] = false;
		// 다른 도시로 가보기 위해 마지막 경로의 도시를 pop
		path.pop_back();
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	vector<int> path(1, 0);
	vector<bool> visited(n, 0);
	visited[0] = 1;
	// path는 temporary한 벡터이다. 함수 내부에서 최소의 경로를 구하기 위해 쓰인다.
	cout << shortestPath(path, visited, 0) << '\n';
	system("pause");
	return 0;
}