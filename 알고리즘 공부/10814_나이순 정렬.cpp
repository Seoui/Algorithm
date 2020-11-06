#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

bool Compare(pair<int, string> p, pair<int, string> q)
{
	if (p.first != q.first) return p.first < q.first;
	else return false;
}

void SortMember(vector<pair<int, string>>& input)
{
	stable_sort(begin(input), end(input), Compare);
	for (auto& i : input)
		cout << i.first << " " << i.second << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<pair<int, string>> input;
	int N;
	cin >> N;
	while (N--) {
		int age;
		string name;
		cin >> age >> name;
		input.push_back(make_pair(age, name));
	}
	SortMember(input);
	return 0;
}