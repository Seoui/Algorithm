#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<string, string> memo;
	int N, M;
	cin >> N >> M;
	while (N--) {
		string a;//address
		string p;//password
		cin >> a >> p;
		memo.insert(make_pair(a, p));
	}

	while (M--) {
		string site;
		cin >> site;
		cout << memo[site] << '\n';
	}
	return 0;
}