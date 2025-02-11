#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

string solution(vector<int> numbers, string hand)
{
	/*플로이드
	const int V = 12;
	int adj[V][V];
	fill(adj[0], adj[V], 987654321);
	adj[0][10] = 1, adj[0][11] = 1, adj[0][8] = 1;
	adj[1][2] = 1, adj[1][4] = 1;
	adj[2][1] = 1, adj[2][5] = 1, adj[2][3] = 1;
	adj[3][2] = 1, adj[3][6] = 1;
	adj[4][1] = 1, adj[4][5] = 1, adj[4][7] = 1;
	adj[5][2] = 1, adj[5][4] = 1, adj[5][6] = 1, adj[5][8] = 1;
	adj[6][3] = 1, adj[6][5] = 1, adj[6][9] = 1;
	adj[7][4] = 1, adj[7][8] = 1, adj[7][10] = 1;
	adj[8][5] = 1, adj[8][7] = 1, adj[8][9] = 1, adj[8][0] = 1;
	adj[9][6] = 1, adj[9][8] = 1, adj[9][11] = 1;
	adj[10][7] = 1, adj[10][0] = 1;
	adj[11][9] = 1, adj[11][0] = 1;

	for (int i = 0; i < V; ++i)
		adj[i][i] = 0;
	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	int num = 0;
	int curl = 10;	// *
	int curr = 11;	// #
	for (int i = 0; i < numbers.size(); ++i) {
		num = numbers[i];
		if (num == 1 || num == 4 || num == 7) {
			curl = num;
			answer += 'L';
		}
		else if (num == 3 || num == 6 || num == 9) {
			curr = num;
			answer += 'R';
		}
		else
		{
			if (adj[curl][num] == adj[curr][num]) {
				if (hand == "right"){
					curr = num;
					answer += 'R';
				}
				else {
					curl = num;
					answer += 'L';
				}
			}
			else if (adj[curl][num] > adj[curr][num]) {
				curr = num;
				answer += 'R';
			}
			else {
				curl = num;
				answer += 'L';
			}
		}
	}*/

	string answer = "";
	vector<pair<int, int>> pad = {
		{ 0, 3 }, { -1, 0 }, { 0, 0 },
		{ 1, 0 }, { -1, 1 }, { 0, 1 },
		{ 1, 1 }, { -1, 2 }, { 0, 2 },
		{ 1, 2 }, { -1, 3 }, { 1, 3 }
	};

	int num = 0;
	int curl = 10;	// *
	int curr = 11;	// #
	for (int i = 0; i < numbers.size(); ++i) {
		num = numbers[i];
		if (num == 1 || num == 4 || num == 7) {
			curl = num;
			answer += 'L';
		}
		else if (num == 3 || num == 6 || num == 9) {
			curr = num;
			answer += 'R';
		}
		else
		{
			int ntol = abs(pad[curl].first - pad[num].first) + abs(pad[curl].second - pad[num].second);
			int ntor = abs(pad[curr].first - pad[num].first) + abs(pad[curr].second - pad[num].second);
			if (ntol == ntor) { // 거리가 같으면
				if (hand == "right"){
					curr = num;
					answer += 'R';
				}
				else {
					curl = num;
					answer += 'L';
				}
			}
			else if (ntol < ntor) { // 왼손이 더 가까우면
				curl = num;
				answer += 'L';
			}
			else { // 오른손이 더 가까우면
				curr = num;
				answer += 'R';
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

	vector<int> n1 = { 1,3,4,5,8,2,1,4,5,9,5 };
	string h1 = "right";
	cout << solution(n1, h1) << endl;

	vector<int> n2 = { 7,0,8,2,8,3,1,5,7,6,2 };
	string h2 = "left";
	cout << solution(n2, h2) << endl;

	vector<int> n3 = { 1,2,3,4,5,6,7,8,9,0 };
	string h3 = "right";
	cout << solution(n3, h3) << endl;
	system("pause");
	return 0;
}