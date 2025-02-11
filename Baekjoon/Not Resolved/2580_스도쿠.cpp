#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vec2 = vector<vector<int>>;
int table[9][9];
int cnt;
bool num[82][10];
bool ret;
vec2 후보들;

void solution(int k)
{
	if (k == cnt) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j)
				cout << table[i][j] << ' ';
			cout << '\n';
		}
		exit(0);
	}

	num[k][0] = false;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (table[i][j] == 0) {
				for (int c = 0; c < 9; ++c) {
					if (table[i][c] != 0)
						num[k][table[i][c]] = false;
					if (table[c][j] != 0)
						num[k][table[c][j]] = false;
				}

				for (int a = 0; a < 3; ++a)
					for (int b = 0; b < 3; ++b)
						num[k][table[i / 3 * 3 + a][j / 3 * 3 + b]] = false;

				for (int p = 1; p <= 9; ++p) {
					if (num[k][p] == true) {
						table[i][j] = p;
						solution(k + 1);
						table[i][j] = 0;
						fill(num[k], num[k] + 10, true);
						num[k][0] = false;
					}
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	fill(num[0], num[81] + 10, true);
	num[0][0] = false;

	for (int i = 0; i < 9; ++i){
		for (int j = 0; j < 9; ++j){
			cin >> table[i][j];
			if (table[i][j] == 0)
				++cnt;
		}
	}
	//후보들.resize(cnt, vector<int>(10, 0));
	solution(0);

	
	system("pause");
	return 0;
}