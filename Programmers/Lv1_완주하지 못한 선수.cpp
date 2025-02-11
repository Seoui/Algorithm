#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
	unordered_map<string, int> hash;
	
	for (int i = 0; i < completion.size(); ++i)
		hash[completion[i]] += 1;

	for (int i = 0; i < participant.size(); ++i) {
		hash[participant[i]] -= 1;
		if (hash[participant[i]] < 0)
			return participant[i];
	}
	return string();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vector<string> p = { "mislav", "stanko", "mislav", "ana" };
	vector<string> c = { "stanko", "ana", "mislav" };
	cout << solution(p, c);
	system("pause");
	return 0;
}