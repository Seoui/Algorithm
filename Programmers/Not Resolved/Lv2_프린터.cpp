#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location)
{
	int answer = 0;
	queue<pair<int, int>> q;
	priority_queue<int> pq;
	for (int i = 0; i < priorities.size(); ++i) {
		q.push(make_pair(priorities[i], i));
		pq.push(priorities[i]);
	}

	while (!pq.empty()) {
		if (pq.top() == q.front().first) {
			answer++;
			if (q.front().second == location)
				break;
			pq.pop();
			q.pop();
		}
		else {
			q.push(q.front());
			q.pop();
		}
	}
		
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	solution({ 2, 1, 3, 2 }, 2);
	solution({ 1, 1, 9, 1, 1, 1 }, 0);
	system("pause");
	return 0;
}