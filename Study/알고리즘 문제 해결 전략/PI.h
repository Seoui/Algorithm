#pragma once

/*
	8.7 문제: 원주율 외우기 (문제 ID: PI, 난이도: 하) - p239

*/
class PI
{
public:
	PI();
	~PI();

	void solution();
	int classify(int a, int b);
	int memorize(int begin);

private:
	/*
		모든 숫자가 같을 때							- 난이도 1
		숫자가 1씩 단조 증가하거나 단조 감소할 때	- 난이도 2
		두 개의 숫자가 번갈아가며 나타날 때			- 난이도 4
		숫자가 등차 수열을 이룰 때					- 난이도 5
		이 외의 모든 경우							- 난이도 10
	*/
	int testCase = 0;		// 테스트 케이스, 최댓값 50인 자연수
	string N;				// 숫자, 8자리 이상 10000자리 이하의 자연수임
							// (문자 8개 이상 10000개 이하인 문자열)
	const int INF = 987654321;
	int cache[10002];
	vector<int> result;
};

