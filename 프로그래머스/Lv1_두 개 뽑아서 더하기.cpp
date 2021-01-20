#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers)
{
	vector<int> answer;
	set<int> s;
	for (int i = 0; i < numbers.size() - 1; ++i)
		for (int j = i + 1; j < numbers.size(); ++j)
			s.insert(numbers[i] + numbers[j]);
	answer.assign(begin(s), end(s));
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vector<int> numbers = { 2, 1, 3, 4, 1 };
	vector<int> ret = solution(numbers);
	for (int& r : ret)
		cout << r;
	system("pause");
	return 0;
}