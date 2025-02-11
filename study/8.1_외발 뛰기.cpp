#include <iostream>
using namespace std;

int board[7][7] = {
	{2, 5, 1, 6, 1, 4, 1},
	{6, 1, 1, 2, 2, 9, 3},
	{7, 2, 3, 2, 1, 3, 1},
	{1, 1, 3, 1, 7, 1, 2},
	{4, 1, 2, 3, 4, 1, 2},
	{3, 3, 1, 2, 3, 4, 1},
	{1, 5, 2, 9, 4, 7, 0} };

int cache[7][7];
int solve(int y, int x)
{
	// 골인 지점에 도착하면 성공!
	if (y==6 && x==6) return true;
	// 범위를 벗어나면 실패
	if (y > 6 || y < 0 || x > 6 || x < 0) return false;

	if (cache[y][x] != -1)
		return cache[y][x];
	return cache[y][x] = (solve(y + board[y][x], x) || solve(y, x + board[y][x]));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(cache, -1, sizeof(int));
	cout << solve(0, 0) << '\n';
	system("pause");
	return 0;
}