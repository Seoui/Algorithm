#include <vector>
#include <iostream>
using namespace std;

int main()
{
	
	int N, M;
	cin >> N >> M;
	vector<vector<int>> v1(N, vector<int>(M));
	vector<vector<int>> v2(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int a;
			cin >> a;
			v1[i][j] = a;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int a;
			cin >> a;
			v2[i][j] = a;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << v1[i][j] + v2[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}