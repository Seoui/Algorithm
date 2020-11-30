#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<string> hear;
	vector<string> result;
	int N, M;
	cin >> N >> M;
	while (N--) {
		string h;
		cin >> h;
		hear.push_back(h);
	}
	sort(begin(hear), end(hear));

	while (M--) {
		string s;
		cin >> s;
		if (binary_search(begin(hear), end(hear), s))
			result.push_back(s);
	}
	sort(begin(result), end(result));

	cout << result.size() << '\n';
	for (auto& r : result)
		cout << r << '\n';
	return 0;
}