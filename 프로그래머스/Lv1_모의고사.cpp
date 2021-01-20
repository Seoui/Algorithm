#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers)
{
	vector<int> answer;
	vector<int> f = { 1,2,3,4,5 };
	vector<int> s = { 2,1,2,3,2,4,2,5 };
	vector<int> t = { 3,3,1,1,2,2,4,4,5,5 };

	int fj = 0, fc = 0;
	int sj = 0, sc = 0;
	int tj = 0, tc = 0;
	for (int i = 0; i < answers.size(); ++i) {
		if (fj == f.size())
			fj = 0;
		if (sj == s.size())
			sj = 0;
		if (tj == t.size())
			tj = 0;

		if (answers[i] == f[fj++])
			fc++;
		if (answers[i] == s[sj++])
			sc++;
		if (answers[i] == t[tj++])
			tc++;
	}

	int m = max(max(fc, sc), tc);
	if (fc == m)
		answer.push_back(1);
	if (sc == m)
		answer.push_back(2);
	if (tc == m)
		answer.push_back(3);

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vector<int> answers = { 1, 3, 2, 4, 2 }; //{ 1,2,3,4,5 };// 
	auto ret = solution(answers);
	for (auto& r : ret)
		cout << r << ' ';
	system("pause");
	return 0;
}