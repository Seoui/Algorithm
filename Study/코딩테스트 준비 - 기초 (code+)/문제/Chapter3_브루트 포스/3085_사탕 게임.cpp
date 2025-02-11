#include <iostream>
#include <string>
#include <vector>
using namespace std;

int check(vector<string>& a)
{
	int n = a.size();
	int ans = 1;
	for (int i = 0; i < n; ++i) {
		int cnt = 1;
		for (int j = 1; j < n; ++j) {
			if (a[i][j] == a[i][j - 1])
				cnt += 1;
			else
				cnt = 1;
			if (ans < cnt) ans = cnt;
		}
		cnt = 1;
		for (int j = 1; j < n; ++j) {
			if (a[j][i] == a[j - 1][i])
				cnt += 1;
			else
				cnt = 1;
			if (ans < cnt) ans = cnt;
		}
	}

	return ans;
}

int check2(vector<string>& a, int start_row, int end_row, int start_col, int end_col)
{
	int n = a.size();
	int ans = 1;
	for (int i = start_row; i <= end_row; ++i) {
		int cnt = 1;
		for (int j = 1; j < n; ++j) {
			if (a[i][j] == a[i][j - 1])
				cnt += 1;
			else
				cnt = 1;
			if (ans < cnt) ans = cnt;
		}
	}

	for (int i = start_col; i <= end_col; ++i) {
		int cnt = 1;
		for (int j = 1; j < n; ++j) {
			if (a[j][i] == a[j - 1][i])
				cnt += 1;
			else
				cnt = 1;
			if (ans < cnt) ans = cnt;
		}
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			// ¿À
			if (j + 1 < n) {
				swap(a[i][j], a[i][j + 1]);
				int temp = check(a);
				//int temp2 = check2(a, i, i, j, j + 1);
				if (ans < temp) ans = temp;
				//if (ans < temp2) ans = temp2;
				swap(a[i][j], a[i][j + 1]);
			}
			// ¾Æ
			if (i + 1 < n) {
				swap(a[i][j], a[i + 1][j]);
				int temp = check(a);
				//int temp2 = check2(a, i, i + 1, j, j);
				if (ans < temp) ans = temp;
				//if (ans < temp2) ans = temp2;
				swap(a[i][j], a[i + 1][j]);
			}
		}
	}
	cout << ans << '\n';
	system("pause");
	return 0;
}