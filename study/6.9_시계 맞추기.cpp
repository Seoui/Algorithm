#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
using namespace std;
/*
���� �Է�
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

// clocks�� �ð�, s�� ���� ���� ����ġ ��ȣ[0, 9]
int solve(vector<int>& clocks, int s)
{
	// ���� ���� ���� ����ġ�� 10��(������ ����) ����ġ��� (��� ����ġ �� �����ôٴ� ��)
	// 12�ÿ� ���ĵǾ� ���� ������ 9999�� ��ȯ
	if (s == 10) return areAligned(clocks) ? 0 : 9999;

	int ret = numeric_limits<int>::max();
	// �ϳ��� ����ġ�� 0~3������ ������ �� �ִ�.
	for (int cnt = 0; cnt < 4; ++cnt) {
		// ret�� �� ���� ���� ����ġ�� (cnt - 1)�� ������ ���� �� ��ư ���� Ƚ��
		// cnt + �� ���� ���� ����ġ�� ������ Ƚ���� ���Ѵٴ� ��
		// solve(clocks, s + 1) -> ���� ����ġ�� ������ ����
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