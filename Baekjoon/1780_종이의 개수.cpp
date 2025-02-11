#include <iostream>
using namespace std;

int ����[2187][2187];
int ret[3];

bool Check(int y, int x, int N)
{
	int first = ����[y][x];
	for (int i = y; i < y + N; ++i)
		for (int j = x; j < x + N; ++j)
			if (first != ����[i][j])
				return false;

	return true;
}

void �����ǰ���(int y, int x, int N)
{
	// ���̰� 1�̸� �� ���� ����
	if (N == 1) {
		ret[����[y][x] + 1] += 1;
		return;
	}

	bool c = Check(y, x, N);
	if (c == false) {
		// �ϳ��� ���̰� �ƴ� �� ���� ����
		int L = N / 3;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				�����ǰ���(y + L * i, x + L * j, L);
	}
	else
		// �ϳ��� ���� �϶�
		ret[����[y][x] + 1] += 1;


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
			cin >> ����[i][j];
	
	�����ǰ���(0, 0, N);
	cout << ret[0] << '\n' << ret[1] << '\n' << ret[2];

	return 0;
}