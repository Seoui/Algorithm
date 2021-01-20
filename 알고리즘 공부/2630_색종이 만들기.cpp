#include <iostream>
#include <utility>
using namespace std;

bool paper[130][130];
int w = 0, b = 0;

void DQ(int y, int x, int size)
{
	bool cur = paper[y][x];

	for (int i = y; i < y + size; ++i) {
		for (int j = x; j < x + size; ++j) {
			if (paper[i][j] != cur) {
				DQ(y, x, size / 2);
				DQ(y + size / 2, x, size / 2);
				DQ(y, x + size / 2, size / 2);
				DQ(y + size / 2, x + size / 2, size / 2);
				return;
			}
		}
	}
	if (cur == 0) w++;
	else b++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> paper[i][j];

	DQ(0, 0, N);
	cout << w << '\n' << b;
	
	system("pause");
	return 0;
}