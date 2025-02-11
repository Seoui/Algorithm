#include <iostream>
using namespace std;

//���� ����ٰ��� �ڵ�
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
			// ���� �ܰ迡�� ������ ���ڰ� �ƴϰų� ������ ��찡 �ƴ϶��
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

// ���� - 1
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
				// ������ ����� �ʾ�����, �̹� �� ���ڸ� ����ߴٸ�, ok = false;
				if (0 <= nx && nx < n && 0 <= ny && ny < m)
					if (c[nx][ny]) 
						ok = false; // -> false�� �Ǹ� �ش� ĭ ���ڴ� ���� ����.
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

// ���� - 2
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

// ���� - 3
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