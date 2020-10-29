#include <iostream>
#include <algorithm>
using namespace std;

int CountSquare(char chess[8][8])
{
	int tw = 0, tb = 0, rw = 0, rb = 0;
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			if ((i + j) % 2 == 0){
				if (chess[i][j] != 'W') 
					rw++;
			}
			else{
				if (chess[i][j] != 'B')
					rb++;
			}
		}
	}
	tw = rw + rb;
	rb = 0;
	rw = 0;
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			if ((i + j) % 2 == 0)
				if (chess[i][j] != 'B')
					rb++;
			else
				if (chess[i][j] != 'W')
					rw++;
		}
	}
	tb = rw + rb;
	return min(tw, tb);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	char board[50][50] = { 0, };
	char chess[8][8] = { 0, };
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j){
			char WB;
			cin >> WB;
			board[i][j] = WB;
		}
	}

	int a = 0, b = 0, cs = 0, result = 987654321;
	while (true){
		if (a > N - 8 || b > M - 8)
			break;
		for (a = 0; a < N - 7; ++a){
			for (b = 0; b < M - 7; ++b){
				for (int i = 0; i < 8; ++i){
					for (int j = 0; j < 8; ++j){
						chess[i][j] = board[i + a][j + b];
						cs = CountSquare(chess);
					}
				}
				result = min(result, cs);
			}
		}
	}
	cout << result << '\n';
	return 0;
}