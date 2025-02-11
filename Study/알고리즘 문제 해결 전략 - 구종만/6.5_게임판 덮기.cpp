#include <iostream>
#include <vector>
using namespace std;

// 4���� Ÿ��, �� ��ϴ� 3ĭ, 1ĭ�� (x, y) ������
const int coverType[4][3][2] = {
	{ { 0, 0 }, { 1, 0 }, { 1, 1 } },	// ��
	{ { 0, 0 }, { 1, 0 }, { 0, 1 } },	// ��
	{ { 0, 0 }, { 1, 0 }, { 1, -1 } },	// ��
	{ { 0, 0 }, { 0, 1 }, { 1, 1 } }	// ��
};

// set�� ���忡�� ����� ���ų� �����.
// delta�� 1�̸� ����, -1�̸� �����
bool set(vector<vector<int>>& board, int y, int x, int type, int delta)
{
	bool ok = true;
	for (int i = 0; i < 3; ++i) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		// ����� ��踦 �����
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
			ok = false;
		// ����� ������ ĭ�� �� �������� �Ѵٸ�
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}

int Cover(vector<vector<int>>& board)
{
	int x = -1, y = -1;
	// �������� ã�´�. ���� ���� ��
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
	// �� for������ �ƹ��ϵ� �Ͼ�� �ʾҴٸ� �������� ��ã�Ҵ�.(�� cover��)
	if (y == -1) return 1;
	int ret = 0;
	// �������� ã������ �� 4���� ���� 4���� Ÿ���� ������� �����
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