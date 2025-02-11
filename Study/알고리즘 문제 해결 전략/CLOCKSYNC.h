#pragma once

/*
	6.8 문제: 시계 맞추기(문제 ID: CLOCKSYNC, 난이도: 중) - p168
	풀긴 풀었지만, 책의 방법도 유효함.
	나는 트릭을 이용해서(스도쿠 풀듯이) 풀었고,
	책은 완전탐색을 이용했기 때문에 책도 참고해야함.
	관련 자료는 프로젝트 파일에 있음. 스프레드 시트파일임.
*/
class CLOCKSYNC
{
public:
	CLOCKSYNC();
	~CLOCKSYNC();

	void Wind(int nSwitch);
	int WindClock();
	void solution();

private:
	int clockArray[16] = { 0, };
	bool SwitchLinkClock[10][16] = { 0, };
	int testCase = 0;
	int nClock = 0;
	int count = 0;
};

