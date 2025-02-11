#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> image;

void dq(int n, int y, int x)
{
	if (n == 1) {
		cout << image[y][x] - '0';
		return;
	}

	int first = image[y][x] - '0';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (first != image[y + i][x + j] - '0') {
				cout << '(';
				dq(n / 2, y, x);
				dq(n / 2, y, x + n / 2);
				dq(n / 2, y + n / 2, x);
				dq(n / 2, y + n / 2, x + n / 2);
				cout << ')';
				return;
			}
		}
	}
	cout << first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	image.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> image[i];
	dq(n, 0, 0);
	return 0;
}