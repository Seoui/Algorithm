#include <iostream>
using namespace std;

int 종이[2187][2187];
int ret[3];

bool Check(int y, int x, int N)
{
	int first = 종이[y][x];
	for (int i = y; i < y + N; ++i)
		for (int j = x; j < x + N; ++j)
			if (first != 종이[i][j])
				return false;

	return true;
}

void 종이의개수(int y, int x, int N)
{
	// 길이가 1이면 한 장의 종이
	if (N == 1) {
		ret[종이[y][x] + 1] += 1;
		return;
	}

	bool c = Check(y, x, N);
	if (c == false) {
		// 하나의 종이가 아닐 때 분할 정복
		int L = N / 3;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				종이의개수(y + L * i, x + L * j, L);
	}
	else
		// 하나의 종이 일때
		ret[종이[y][x] + 1] += 1;


	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for(int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> 종이[i][j];
	
	종이의개수(0, 0, N);
	cout << ret[0] << '\n' << ret[1] << '\n' << ret[2];

	return 0;
}