#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

vector<int> solution(int N, vector<int> stages) 
{
	/*
	vector<int> answer;
	map<int, int> m;
	for (int i = 0; i < stages.size(); ++i)
		m[stages[i]]++;

	float amount = stages.size();
	for (int i = 1; i < N + 1; ++i) {
		float ½ÇÆÐÀ² = m[i] / (amount - m[i - 1]);

	}
	int a = 5;
	*/
	
	vector<int> answer;
	vector<pair<float, int>> sn(N + 2, { 0.0f, 0 });
	map<float, int> m;
	for (int i = 0; i < stages.size(); ++i) {
		sn[stages[i]].first++;
		sn[stages[i]].second = stages[i];
	}

	float den = (float)stages.size();
	for (int i = 1; i < sn.size(); ++i) {
		float tmp = sn[i].first;
		sn[i].first = sn[i].first / den;
		den -= tmp;
	}
	
	/*
	auto compare = [](pair<float, int> a, pair<float, int> b) {
		if (a.second > b.second) return true;
		else if (a.second == b.second) {}
			
	};*/
	sort(begin(sn), end(sn) - 1, greater<pair<float, int>>());
	
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	solution(5, { 2, 1, 2, 6, 2, 4, 3, 3 });
	solution(4, { 4, 4, 4, 4, 4 });
	system("pause");
	return 0;
}