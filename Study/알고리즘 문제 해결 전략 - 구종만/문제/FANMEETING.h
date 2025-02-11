#pragma once
/*
	7.6 문제: 팬미팅 (문제 ID: FANMEETING, 난이도: 상) - p201
	karatsuba 곱셈 알고리즘이 핵심이다.
	지금 적혀있는 답은 틀린건 아니지만, 시간초과다.
	시간을 줄이기 위해서는 karatsuba 곱셈 알고리즘을 다시 한번 보길
	-p183 임.
*/
class FANMEETING
{
public:
	FANMEETING();
	~FANMEETING();

	void solution();
	int Hug(string&, string&);
	string ShiftString(string& str);

private:
	int testCase = 0;			// 테스트 케이스, 최댓값 20인 자연수
	vector<int> ret;
};

