#pragma once
/*
	7.4 문제: 울타리 잘라내기 (문제 ID: FENCE, 난이도: 중) - p195
*/
class FENCE
{
public:
	FENCE();
	~FENCE();

	void solution();

	// O(n^2) 알고리즘
	int bruteForce(const vector<int>& h);
	// 분할 정복 알고리즘
	int solve(int left, int right);

private:
	int curCase = 0;
	int testCase = 0;		// 테스트케이스, 최댓값 50인 자연수
	int nfence = 0;			// 판자개수, 최댓값 20000인 자연수
	vector<int> ret;		// 최대 직사각형의 크기
	vector<vector<int>> h;	// 각 판자의 높이, 최댓값 10000인 자연수
	/* 실패
	int RectArea(int i);
	int ContinuousFence(int curIdx, int minHeight, int k);
private:
	int testCase = 0;			// 테스트케이스, 최댓값 50인 자연수
	int nfence = 0;				// 판자개수, 최댓값 20000인 자연수
	vector<vector<int>> fenceHeight;	// 각 판자의 높이, 최댓값 10000인 자연수
	vector<int> ret;			// 최대 직사각형의 크기
	vector<int>::iterator it;
	*/
};

