#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void BuildRank(vector<pair<int, int>>& input)
{
	vector<int> ranking(input.size());
	for (size_t i = 0; i < input.size(); ++i) {
		int biggerThanMe = 0;
		for (size_t j = 0; j < input.size(); ++j) {
			if (input[i].first < input[j].first &&
				input[i].second < input[j].second)
				++biggerThanMe;
		}
		ranking[i] = biggerThanMe + 1;
	}

	for (auto& r : ranking)
		cout << r << " ";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vector<pair<int, int>> input;
	int N;
	cin >> N;
	while (N--) {
		int weight, height;
		cin >> weight >> height;
		input.push_back(make_pair(weight, height));
	}
	BuildRank(input);
	cout << '\n';
	return 0;
}