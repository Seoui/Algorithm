#include <iostream>
#include <algorithm>
using namespace std;

int n, triangle[100][100];
int cache[100][100];
// (y, x) ��ü���� �� �Ʒ��ٱ��� �������鼭 ���� �� �ִ� �ִ� ����� ���� ��ȯ�Ѵ�.
int path(int y, int x)
{
	if (y == n - 1)return triangle[y][x];

	int& ret = cache[y][x];
	if (ret != -1) return ret;

	return ret = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}