#include <iostream>
#include <vector>
using namespace std;

// 4가지 타입, 각 블록당 3칸, 1칸은 (x, y) 순서쌍
const int coverType[4][3][2] = {
	{ { 0, 0 }, { 1, 0 }, { 1, 1 } },	// └
	{ { 0, 0 }, { 1, 0 }, { 0, 1 } },	// ┌
	{ { 0, 0 }, { 1, 0 }, { 1, -1 } },	// ┘
	{ { 0, 0 }, { 0, 1 }, { 1, 1 } }	// ┐
};

// set은 보드에서 블록을 덮거나 지운다.
// delta가 1이면 덮고, -1이면 지운다
bool set(vector<vector<int>>& board, int y, int x, int type, int delta)
{
	bool ok = true;
	for (int i = 0; i < 3; ++i) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		// 블록이 경계를 벗어나면
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
			ok = false;
		// 블록이 검정색 칸을 또 덮으려고 한다면
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}

int Cover(vector<vector<int>>& board)
{
	int x = -1, y = -1;
	// 시작점을 찾는다. 가장 왼쪽 위
	for (int h = 0; h < board.size(); ++h) {
		for (int w = 0; w < board[h].size(); ++w) {
			if (board[h][w] == 0) {
				x = w;
				y = h;
				break;
			}
		}
		if (y != -1) break;
	}
	// 위 for문에서 아무일도 일어나지 않았다면 시작점을 못찾았다.(다 cover함)
	if (y == -1) return 1;
	int ret = 0;
	// 시작점을 찾았으면 총 4번에 걸쳐 4가지 타입의 블록으로 덮어본다
	for (int type = 0; type < 4; ++type) {
		if (set(board, y, x, type, 1))
			ret += Cover(board);
		set(board, y, x, type, -1);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	/*
		3
		3 7
		#.....#
		#.....#
		##...##
		3 7
		#.....#
		#.....#
		##..###
		8 10
		##########
		#........#
		#........#
		#........#
		#........#
		#........#
		#........#
		##########
		C: Test case
		H: Height[1, 20]
		W: Width [1, 20]
	*/
	vector<vector<int>> board;
	vector<int> w;
	int C, H, W;
	cin >> C;
	while (C--) {
		cin >> H >> W;
		for(int i = 0; i < H; ++i) {
			for(int j = 0; j < W; ++j) {
				char b;
				cin >> b;
				if (b == '#')
					w.push_back(1);
				else if (b == '.')
					w.push_back(0);
			}
			board.push_back(w);
			w.clear(); 
		}
		cout << Cover(board) << '\n';
		board.clear();
	}
	system("pause");
	return 0;
}