#pragma once

/*
	8.5 ����: ��ģ LIS (���� ID: JLIS, ���̵�: ��) - p236
	��ģ LIS - JLIS (Joined Longest Increasing Subsequence)

	�ذ� ����..
*/

class JLIS
{
public:
	JLIS();
	~JLIS();

	int lis(const vector<int>& A);
	int jlis(int indexA, int indexB);
	void solution();
private:
	const long long NEGINF = numeric_limits<long long>::min();
	int n = 3, m = 3;
	int A[3] = { 1, 2, 4 };
	int B[3] = { 3, 4, 7 };
	int cache[101][100];
};

