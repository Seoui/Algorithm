#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
	int answer = 0;
	vector<pair<int, int>> bg;
	bg.push_back(make_pair(truck_weights[0], 0));

	while (true) {
		for (int i = 0; i < bg.size(); ++i) {
			if (bg[i].second == bridge_length) {
				bg.erase(begin(bg));
			}
				bg.second++;
		}
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	solution(2, 10, { 7, 4, 5, 6 });
	solution(100, 100, { 10 });
	solution(100, 100, { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 });
	system("pause");
	return 0;
}