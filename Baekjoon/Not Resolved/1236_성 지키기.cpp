#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vector<string> building;
	int f;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i){
		string row;
		cin >> row;
		building.push_back(row);
	}
	for (int i = 0; i < n; ++i) {
		f = building[i].find('x');
		if(f == -1)
	}
	system("pause");
	return 0;
}