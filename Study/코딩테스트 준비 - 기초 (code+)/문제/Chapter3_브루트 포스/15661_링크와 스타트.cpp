#include <iostream>
#include <vector>
using namespace std;

int n;
int s[20][20]{};

int go(int index, vector<int>& first, vector<int>& second)
{
	// 팀을 모두 분배한 경우
	if (index == n) {
		if (first.size() == 0) return -1;
		if (second.size() == 0) return -1;
		int t1 = 0;
		int t2 = 0;
		int l1 = int(first.size());
		int l2 = int(second.size());
		for (int i = 0; i < l1; ++i){
			for (int j = 0; j < l1; ++j){
				if (i == j) continue;
				t1 += s[first[i]][first[j]];
			}
		}
		for (int i = 0; i < l2; ++i) {
			for (int j = 0; j < l2; ++j) {
				if (i == j) continue;
				t2 += s[second[i]][second[j]];
			}
		}
		int diff = t1 - t2;
		if (diff < 0) diff = -diff;
		return diff;
	}

	// 팀을 분배하자.
	int ans = -1;
	first.push_back(index);
	int t1 = go(index + 1, first, second);
	if (ans == -1 || (t1 != -1 && ans > t1))
		ans = t1;
	first.pop_back();

	second.push_back(index);
	int t2 = go(index + 1, first, second);
	if (ans == -1 || (t2 != -1 && ans > t2))
		ans = t2;
	second.pop_back();

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> s[i][j];
	vector<int> first, second;
	cout << go(0, first, second) << '\n';
	system("pause");
	return 0;
}