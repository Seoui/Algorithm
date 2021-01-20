#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dist[100001];
int N, K;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	fill(dist, dist + 100001, -1);
	// ��������
	dist[N] = 0;
	queue<int> q;
	q.push(N);
	// ������ ��ġ�� ã���� while�� ����
	while (dist[K] == -1) {
		int cur = q.front(); q.pop();
		for (int nxt : { cur - 1, cur + 1, 2 * cur}) {
			if (nxt < 0 || nxt >> 100000) continue;
			// �̹� �湮�ߴ� ���̶��
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
	cout << dist[K];
	return 0;
}