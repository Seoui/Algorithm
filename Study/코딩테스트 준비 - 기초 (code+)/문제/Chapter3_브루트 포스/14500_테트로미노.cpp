#include <iostream>
using namespace std;
// 백준 - 1
/*
int a[500][500];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (j + 3 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i][j + 3];
				if (ans < temp) ans = temp;
			}
			if (i + 3 < n) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 3][j];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j + 2 < m) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2];
				if (ans < temp) ans = temp;
			}
			if (i + 2 < n && j + 1 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 2][j];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 2];
				if (ans < temp) ans = temp;
			}
			if (i + 2 < n && j - 1 >= 0) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j - 1];
				if (ans < temp) ans = temp;
			}
			if (i - 1 >= 0 && j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i - 1][j + 2];
				if (ans < temp) ans = temp;
			}
			if (i + 2 < n && j + 1 < m) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j + 1];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j];
				if (ans < temp) ans = temp;
			}
			if (i + 2 < n && j + 1 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 2][j + 1];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j + 1 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
				if (ans < temp) ans = temp;
			}
			if (i - 1 >= 0 && j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i - 1][j + 1] + a[i - 1][j + 2];
				if (ans < temp) ans = temp;
			}
			if (i + 2 < n && j + 1 < m) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 2][j + 1];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j + 2];
				if (ans < temp) ans = temp;
			}
			if (i + 2 < n && j - 1 >= 0) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 1][j - 1] + a[i + 2][j - 1];
				if (ans < temp) ans = temp;
			}
			if (j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i][j + 2];
				if (i - 1 >= 0) {
					int temp2 = temp + a[i - 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
				if (i + 1 < n) {
					int temp2 = temp + a[i + 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
			}
			if (i + 2 < n) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 2][j];
				if (j + 1 < m) {
					int temp2 = temp + a[i + 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
				if (j - 1 >= 0) {
					int temp2 = temp + a[i + 1][j - 1];
					if (ans < temp2) ans = temp2;
				}
			}
		}
	}
	system("pause");
	return 0;
}*/

// 백준 - 2
int a[500][500];
int block[19][3][2] = {
	{{0,1}, {0,2}, {0,3}},
	{{1,0}, {2,0}, {3,0}},
	{{1,0}, {1,1}, {1,2}},
	{{0,1}, {1,0}, {2,0}},
	{{0,1}, {0,2}, {1,2}},
	{{1,0}, {2,0}, {2,-1}},
	{{0,1}, {0,2}, {-1,2}},
	{{1,0}, {2,0}, {2,1}},
	{{0,1}, {0,2}, {1,0}},
	{{0,1}, {1,1}, {2,1}},
	{{0,1}, {1,0}, {1,1}},
	{{0,1}, {-1,1}, {-1,2}},
	{{1,0}, {1,1}, {2,1}},
	{{0,1}, {1,1}, {1,2}},
	{{1,0}, {1,-1}, {2,-1}},
	{{0,1}, {0,2}, {-1,1}},
	{{0,1}, {0,2}, {1,1}},
	{{1,0}, {2,0}, {1,1}},
	{{1,0}, {2,0}, {1,-1}},
};
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 19; k++) {
				bool ok = true;
				int sum = a[i][j];
				for (int l = 0; l < 3; l++) {
					int x = i + block[k][l][0];
					int y = j + block[k][l][1];
					if (0 <= x && x < n && 0 <= y && y < m) {
						sum += a[x][y];
					}
					else {
						ok = false;
						break;
					}
				}
				if (ok && ans < sum) {
					ans = sum;
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}