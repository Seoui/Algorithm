#pragma once
/*
	6.5 문제: 게임판 덮기(문제 ID: BOARDCOVER, 난이도: 하) - p159
*/
class BOARDCOVER
{
public:
	BOARDCOVER();
	~BOARDCOVER();

	bool set(vector<vector<int>>& board, int y, int x, int type, int delta);
	int cover(vector<vector<int>>& board);
	void solution();

private:
	const int coverType[4][3][2] = {
		{ {0, 0}, {1, 0}, {0, 1} },
		{ {0, 0}, {0, 1}, {1, 1} },
		{ {0, 0}, {1, 0}, {1, 1} },
		{ {0, 0}, {1, 0}, {1, -1} }
	};

	int testCase	= 0;
	int height		= 0;
	int width		= 0;
	char inputChar	= 0;
	vector<vector<int>> board;
	vector<int> boardY;
	vector<int> ret;
	
};

