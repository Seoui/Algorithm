#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<string, int> dogamS;
	map<int, string> dogamI;
	int N, M, No = 1;
	cin >> N >> M;
	while (N--) {
		string pkm;
		cin >> pkm;
		dogamS.insert(make_pair(pkm, No));
		dogamI.insert(make_pair(No++, pkm));
	}
	
	while (M--) {
		string p;
		cin >> p;
		if (isdigit(p[0]))
			cout << dogamI[stoi(p)] << '\n';
		else
			cout << dogamS[p] << '\n';
	}
	return 0;
}