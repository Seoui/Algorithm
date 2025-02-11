#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b)
{
	return a.second > b.second;
}

int main()
{
	int num_w;
	map<string, int> m;
	cin >> num_w;
	for (int i = 0; i < num_w; ++i) {
		string str;
		cin >> str;
		m.insert({ str, str.length() });
	}
	vector<pair<string, int>> v(begin(m), end(m));
	sort(begin(v), end(v), compare);
	for (auto& ev : v)
		cout << ev.first.c_str() << '\n';
	return 0;
}