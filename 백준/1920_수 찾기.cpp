#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> input;
	vector<int> num;
	int N;
	cin >> N;
	while (N--) {
		int a;
		cin >> a;
		input.push_back(a);
	}
	int M;
	cin >> M;
	while (M--) {
		int b;
		cin >> b;
		num.push_back(b);
	}

	sort(begin(input), end(input));
	for (auto& n : num) {
		if (binary_search(begin(input), end(input), n))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	return 0;
}