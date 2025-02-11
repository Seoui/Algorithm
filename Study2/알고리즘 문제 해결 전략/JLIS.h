#pragma once

/*
	8.5 문제: 합친 LIS (문제 ID: JLIS, 난이도: 하) - p236
	합친 LIS - JLIS (Joined Longest Increasing Subsequence)

	해결 못함..
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

