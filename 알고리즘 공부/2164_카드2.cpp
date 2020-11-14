#include <iostream>
#include <queue>
using namespace std;
// 2164 Ä«µå2
void RemainedNumber(queue<int>& q)
{
	while (q.size() != 1) {
		q.pop();
		int repush = q.front();
		q.pop();
		q.push(repush);
	}
	cout << q.back() << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	queue<int> nums;
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		nums.push(i);
	RemainedNumber(nums);
	return 0;
}