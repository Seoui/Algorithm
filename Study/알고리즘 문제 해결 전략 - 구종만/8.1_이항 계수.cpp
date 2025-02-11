#include <iostream>
using namespace std;

// ���
int bino(int n, int r) // ���װ��: binomial coefficient
{
	// ���� ���: n = r (��� ���Ҹ� �� ���� ���) Ȥ�� r = 0 (�� ���Ұ� ���� ���)
	if (r == 0 || n == r) return 1;
	return bino(n - 1, r - 1) + bino(n - 1, r);
}

// ������ȹ��
int cache[30][30];
int bino2(int n, int r)
{
	if (r == 0 || n == r) return 1;
	if (cache[n][r] != -1)
		return cache[n][r];
	return cache[n][r] = bino2(n - 1, r - 1) + bino2(n - 1, r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	system("pause");
	return 0;
}