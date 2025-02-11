#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
using namespace std;
/*
예제 입력
2
12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12
12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6
*/

vector<vector<int>> switches = {
	{ 0, 1, 2 },
	{ 3, 7, 9, 11 },
	{ 4, 10, 14, 15 },
	{ 0, 4, 5, 6, 7 },
	{ 6, 7, 8, 10, 12 },
	{ 0, 2, 14, 15 },
	{ 3, 14, 15 },
	{ 4, 5, 7, 14, 15 },
	{ 1, 2, 3, 4, 5 },
	{ 3, 4, 5, 9, 13 }
};

bool areAligned(const vector<int>& clocks)
{
	for (auto& c : clocks)
		if (c != 12) return false;
	return true;
}

void push(vector<int>& clocks, int s)
{
	for (auto iter = begin(switches[s]); iter != end(switches[s]); ++iter) {
		clocks[*iter] += 3;
		if (clocks[*iter] == 15) 
			clocks[*iter] = 3;
	}
}

// clocks는 시계, s는 현재 누를 스위치 번호[0, 9]
int solve(vector<int>& clocks, int s)
{
	// 만약 현재 누를 스위치가 10번(마지막 다음) 스위치라면 (모든 스위치 다 눌러봤다는 뜻)
	// 12시에 정렬되어 있지 않으면 9999를 반환
	if (s == 10) return areAligned(clocks) ? 0 : 9999;

	int ret = numeric_limits<int>::max();
	// 하나의 스위치는 0~3번까지 눌러볼 수 있다.
	for (int cnt = 0; cnt < 4; ++cnt) {
		// ret은 이 전에 현재 스위치를 (cnt - 1)번 눌렀을 때의 총 버튼 누름 횟수
		// cnt + 는 것은 현재 스위치를 눌러본 횟수를 더한다는 것
		// solve(clocks, s + 1) -> 다음 스위치를 누르러 간다
		ret = min(ret, cnt + solve(clocks, s + 1));
		push(clocks, s);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> clocks(16, 0);
	int C;
	cin >> C;
	while (C--) {
		for (int i = 0; i < 16; ++i) {
			int c;
			cin >> c;
			clocks[i] = c;
		}
		cout << solve(clocks, 0) << '\n';
		clocks.resize(16, 0);
	}
	system("pause");
	return 0;
}