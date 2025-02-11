// 백준 - 2 비트마스크

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];
	
	int ans = numeric_limits<int>::max();
	for (int i = 0; i < (1 << n); ++i) {
		vector<int> teamOne;
		vector<int> teamTwo;
		for (int k = 0; k < n; ++k) {
			if (i & (1 << k))// 1번팀
				teamOne.push_back(k);
			else
				teamTwo.push_back(k);
		}
		if (teamOne.size() != n / 2) continue;
		int sumOne = 0, sumTwo = 0;
		for (int i = 0; i < n / 2; ++i) {
			for (int j = 0; j < n / 2; ++j) {
				if (i == j) continue;
				sumOne += v[teamOne[i]][teamOne[j]];
				sumTwo += v[teamTwo[i]][teamTwo[j]];
			}
		}
		int differ = abs(sumOne - sumTwo);
		ans = ans < differ ? ans : differ;
	}
	cout << ans;
	system("pause");
	return 0;
}

// 백준 - 1
/*
#include <iostream>
#include <vector>
using namespace std;

int s[20][20]{};
int n;

int go(int index, vector<int>& first, vector<int>& second)
{
	// 사람들을 모두 각 팀에 분배 완료하였다.
	if (index == n) {
		if (first.size() != n / 2) return -1;
		if (second.size() != n / 2) return -1;

		int t1 = 0;
		int t2 = 0;
		for (int i = 0; i < n / 2; ++i) {
			for (int j = 0; j < n / 2; ++j) {
				if (i == j) continue;
				// first[i] = 1팀에 i번째 팀원,...
				t1 += s[first[i]][first[j]];
				t2 += s[second[i]][second[j]];
			}
		}
		int diff = t1 - t2;
		if (diff < 0) diff = -diff;
		return diff;
	}
	
	// 불가능한 경우
	if (first.size() > n / 2) return -1;
	if (second.size() > n / 2) return -1;

	// 사람들을 각 팀에 분배한다.
	int ans = -1;
	// index번 사람을 1팀에 분배한다.
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
		for(int j = 0; j < n; ++j)
			cin >> s[i][j];

	vector<int> first, second;
	cout << go(0, first, second) << '\n';
	system("pause");
	return 0;
}*/

// 서의
/*
#include <iostream>
#include <limits>
using namespace std;

int n, in, total;
int s[21][21];
int x[21];
int ret = numeric_limits<int>::max();

void dfs(int idx, int cnt, int sum)
{
	if (cnt == n / 2) {
		if (ret > abs(sum)) ret = abs(sum);
		return;
	}

	if (idx < n - 1) {
		dfs(idx + 1, cnt + 1, sum - x[idx]);
		dfs(idx + 1, cnt, sum);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> in;
			total += in;
			x[i] += in;
			x[j] += in;
		}
	}
	dfs(0, 0, total);
	cout << ret << endl;
	system("pause");
	return 0;
}*/

/* 이게 정답
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int n, m;
int s[21][21];
int start[11];
int link[11];
bool picked[21];
int ret = numeric_limits<int>::max();

int solution(int k, int p)
{
	if (k == m) {
		int ss = 0;
		int ls = 0;
		for (int i = 1, t = 0; i <= n; ++i)
			if (!picked[i])
				link[t++] = i;

		for (int i = 0; i < m; ++i) {
			for (int j = i + 1; j < m; ++j) {
				ss += s[start[i] - 1][start[j] - 1] + s[start[j] - 1][start[i] - 1];
				ls += s[link[i] - 1][link[j] - 1] + s[link[j] - 1][link[i] - 1];
			}
		}

		return abs(ss - ls);
	}

	for (int i = p + 1; i <= n; ++i) {
		if (!picked[i]) {
			start[k] = i;
			picked[i] = 1;
			ret = min(ret, solution(k + 1, i));
			picked[i] = 0;
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	m = n / 2;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> s[i][j];
	cout << solution(0, 0) << endl;
	return 0;
}*/