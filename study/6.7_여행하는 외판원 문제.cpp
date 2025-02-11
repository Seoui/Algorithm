#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

int n;					// ������ �� [1, 10]
double dist[10][10];	// ���� ������ �Ÿ�, dist[y][x] = y���ÿ� x���� ������ �Ÿ�

double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength)
{
	if (path.size() == n)
		return currentLength + dist[path[0]][path.back()];	// ?????????????????????????????????�ڿ� dist�� �� ���ϴ°ɱ�
	double ret = numeric_limits<double>::max();
	for (int next = 1; next < n; ++next) {
		// �̹� �湮�� ���ö�� continue�ؼ� next���� ������ �ѱ��(++next)
		if (visited[next]) continue;
		int here = path.back();
		path.push_back(next);
		visited[next] = true;
		// ������ ��θ� ��ͷ� 
		double cand = shortestPath(path, visited, currentLength + dist[here][next]);
		ret = min(ret, cand);
		// �Ʒ� �� ���� ���� for���� ���� �ʱ�ȭ~!
		// �ٽ� �湮 ���Ѱ�����(�ʱ�ȭ)
		visited[next] = false;
		// �ٸ� ���÷� ������ ���� ������ ����� ���ø� pop
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
	// path�� temporary�� �����̴�. �Լ� ���ο��� �ּ��� ��θ� ���ϱ� ���� ���δ�.
	cout << shortestPath(path, visited, 0) << '\n';
	system("pause");
	return 0;
}