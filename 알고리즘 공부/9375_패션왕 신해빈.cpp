#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	unordered_map<string, int> hMap;
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i) {
			string name, type;
			cin >> name >> type;
			if (hMap.find(type) != end(hMap))// type이 이미 있다면
				hMap[type]++;
			else
				hMap.insert({ type, 1 });
		}
		int ret = 1;
		for (auto& h : hMap)
			ret *= h.second + 1;
		cout << ret - 1 << '\n';
		hMap.clear();
	}

	system("pause");
	return 0;
}