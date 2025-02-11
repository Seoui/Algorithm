#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
	vector<int> answer;
	for (int c = 0; c < commands.size(); ++c) {
		int i = commands[c][0];
		int j = commands[c][1];
		int k = commands[c][2];
		vector<int> tmp(begin(array) + i - 1, begin(array) + j);
		sort(begin(tmp), end(tmp));
		answer.push_back(tmp[k - 1]);
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> ary = { 1,5, 2, 6, 3, 7, 4 };
	vector<vector<int>> com = { {2, 5, 3}, {4, 4, 1}, {1, 7, 3} };
	auto vec = solution(ary, com);
	for (auto& v : vec)
		cout << v << ' ';
	cout << '\n';
	system("pause");
	return 0;
}