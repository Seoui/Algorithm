#include <iostream>
using namespace std;

//내가 만들다가만 코드
/* 
int n, m, k;
int a[11][11];

int solution(int sel_i, int sel_j, int selected, int maxSum)
{
	if (selected == k)
		return maxSum;

	int maxValue = -10001;
	int max_i = 0, max_j = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			// 이전 단계에서 선택한 숫자가 아니거나 인접한 경우가 아니라면
			if (sel_i != i && sel_j != j ||
				((sel_i - 1 != i && sel_j != j) &&
				(sel_i + 1 != i && sel_j != j) &&
				(sel_i != i && sel_j - 1 != j) &&
				(sel_i != i && sel_j + 1 != j))) {
				if (maxValue < a[i][j]) {
					max_i = i;
					max_j = j;
					maxValue = a[i][j];
				}
			}
		}
	}

	return solution(max_i, max_j, selected + 1, maxSum + maxValue);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> k;
	int maxValue = -10001;
	int max_i = 0, max_j = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> a[i][j];
			if (maxValue < a[i][j]){
				max_i = i;
				max_j = j;
				maxValue = a[i][j];
			}
		}
	}
	cout << solution(max_i, max_j, 1, maxValue) << '\n';
	system("pause");
	return 0;
}*/

// 백준 - 1
/*
#include <limits>
int ans = numeric_limits<int>::min();
int n, m, k;
int a[10][10];
bool c[10][10];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void go(int cnt, int sum)
{
	if (cnt == k){
		if (ans < sum) ans = sum;
		return;
	}
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (c[x][y]) continue;
			bool ok = true;
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				// 범위에 벗어나지 않았지만, 이미 그 숫자를 사용했다면, ok = false;
				if (0 <= nx && nx < n && 0 <= ny && ny < m)
					if (c[nx][ny]) 
						ok = false; // -> false가 되면 해당 칸 숫자는 선택 못함.
				if (ok) {
					c[x][y] = true;
					go(cnt + 1, sum + a[x][y]);
					c[x][y] = false;
				}
			}
		}
	}
	
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];

	go(0, 0);
	cout << ans << '\n';
	return 0;
}*/

// 백준 - 2
/*
#include <iostream>
using namespace std;
int a[10][10];
bool c[10][10];
int n, m, k;
int ans = -2147483647;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void go(int px, int py, int cnt, int sum) {
	if (cnt == k) {
		if (ans < sum) ans = sum;
		return;
	}
	for (int x = px; x < n; x++) {
		for (int y = (x == px ? py : 0); y < m; y++) {
			if (c[x][y]) continue;
			bool ok = true;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < m) {
					if (c[nx][ny]) ok = false;
				}
			}
			if (ok) {
				c[x][y] = true;
				go(x, y, cnt + 1, sum + a[x][y]);
				c[x][y] = false;
			}
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	go(0, 0, 0, 0);
	cout << ans << '\n';
	return 0;
}*/

// 백준 - 3
#include <iostream>
using namespace std;
int a[10][10];
bool c[10][10];
int n, m, k;
int ans = -2147483647;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void go(int prev, int cnt, int sum) {
	if (cnt == k) {
		if (ans < sum) ans = sum;
		return;
	}
	for (int j = prev + 1; j < n*m; j++) {
		int x = j / m;
		int y = j % m;
		if (c[x][y]) continue;
		bool ok = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (c[nx][ny]) ok = false;
			}
		}
		if (ok) {
			c[x][y] = true;
			go(x*m + y, cnt + 1, sum + a[x][y]);
			c[x][y] = false;
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	go(-1, 0, 0);
	cout << ans << '\n';
	return 0;
}