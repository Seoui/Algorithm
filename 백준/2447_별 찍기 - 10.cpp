#include <iostream>
#include <algorithm>
using namespace std;

char map[2187][2187];

void solution(int y, int x, int n)
{
	if (n == 1) {
		map[y][x] = '*';
		return;
	}

	int div = n / 3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == 1 && j == 1) continue;
			solution(y + (div * i), x + (div * j), div);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	fill(map[0], map[2186] + 2187, ' ');
	int N;
	cin >> N;
	solution(0, 0, N);

	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j)
			cout << map[i][j];
		cout << '\n';
	}
	
	system("pause");
	return 0;
}