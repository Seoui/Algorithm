#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Josephus(int N, int K)
{
	queue<int> people;
	vector<int> result;
	for (int i = 0; i < N; ++i)
		people.push(i + 1);
	while (true) {
		if (people.size() == 1) {
			result.push_back(people.front());
			break;
		}
		else {
			for (int i = 0; i < K - 1; ++i) {
				people.push(people.front());
				people.pop();
			}
			result.push_back(people.front());
			people.pop();
		}
	}
	cout << "<";
	for (size_t i = 0; i < result.size() - 1; ++i)
		cout << result[i] << ", ";
	cout << result.back() << ">\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;
	Josephus(N, K);
	return 0;
}