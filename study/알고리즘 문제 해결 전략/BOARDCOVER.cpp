#include "SeouiAlgorithm.h"

BOARDCOVER::BOARDCOVER()
{
}

BOARDCOVER::~BOARDCOVER()
{
}

bool BOARDCOVER::set(vector<vector<int>>& board, int y, int x, int type, int delta)
{
	bool ok = true;
	for (int i = 0;i < 3;i++)
	{
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if ((size_t)ny < 0 || (size_t)ny >= board.size() || (size_t)nx < 0 || (size_t)nx >= board[0].size())
			ok = false;
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}

	return ok;
}

int BOARDCOVER::cover(vector<vector<int>>& board)
{
	int y = -1, x = -1;
	for (size_t i = 0;i < board.size();i++)
	{
		for (size_t j = 0;j < board[i].size();j++)
		{
			if (board[i][j] == 0)
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}

	if (y == -1) return 1;

	int ret = 0;
	for (int type = 0;type < 4;type++)
	{
		if (set(board, y, x, type, 1))
			ret += cover(board);
		set(board, y, x, type, -1);
	}

	return ret;
}

void BOARDCOVER::solution()
{
	cin >> testCase;
	while (testCase--)
	{
		cin >> height >> width;
		for (int i = 0; i < height;i++)
		{
			for (int j = 0; j < width; j++)
			{
				cin >> inputChar;
				if (inputChar == '#')
					boardY.push_back(1);
				else if (inputChar == '.')
					boardY.push_back(0);
			}
			board.push_back(boardY);
			boardY.clear();
		}
		ret.push_back(cover(board));
		board.clear();
	}

	for (auto& r : ret)
		cout << r << "\n";
}
