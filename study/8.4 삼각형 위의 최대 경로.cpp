#include <iostream>
#include <algorithm>
using namespace std;

int n, triangle[100][100];
int cache[100][100];
// (y, x) 위체부터 맨 아래줄까지 내려가면서 얻을 수 있는 최대 경로의 합을 반환한다.
int path(int y, int x)
{
	if (y == n - 1)return triangle[y][x];

	int& ret = cache[y][x];
	if (ret != -1) return ret;

	return ret = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}