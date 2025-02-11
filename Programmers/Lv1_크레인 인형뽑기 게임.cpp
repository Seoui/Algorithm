#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) 
{
	int answer = 0;
	stack<int> stk;
	for (int i = 0; i < moves.size(); ++i) {
		for (int j = 0; j < board[0].size(); ++j) {
			int& c = board[j][moves[i] - 1];
			if (c != 0) {
				if (stk.empty()) {
					stk.push(c);
					c = 0;
					break;
				}
				if (stk.top() == c) {
					stk.pop();
					answer += 2;
				}
				else
					stk.push(c);
				c = 0;
				break;
			}
		}
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<vector<int>> board = {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 3},
		{0, 2, 5, 0, 1},
		{4, 2, 4, 4, 2},
		{3, 5, 1, 3, 1}
	};
	vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };
	cout << solution(board, moves);
	system("pause");
	return 0;
}