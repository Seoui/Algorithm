#include <iostream>
#include <vector>
#include <string>
using namespace std;

int cache[101][101];
string W, S;

bool matchMemoized(int w, int s)
{
	int& ret = cache[w][s];
	if (ret != -1) return ret;

	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s]))
		return ret = matchMemoized(w + 1, s + 1);

	if (w == W.size()) return ret = (s == S.size());
	if (W[w] == '*') {
		if (matchMemoized(w + 1, s) || (s < S.size() && matchMemoized(w, s + 1)))
			return ret = 1;
	}

}

void FindMatch(string& w, vector<string>& strs)
{
	for (auto& s : strs)
		if (Match(w, s))
			cout << s << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	vector<string> names;
	int C;
	cin >> C;
	while (C--) {
		string wildCard;
		int numStr;
		cin >> wildCard >> numStr;
		for (int i = 0; i < numStr; ++i) {
			string str;
			cin >> str;
			names.push_back(str);
		}
		FindMatch(wildCard, names);
	}
	system("pause");
	return 0;
}