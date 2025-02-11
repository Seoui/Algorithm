#pragma once

/*
	6.8 ����: �ð� ���߱�(���� ID: CLOCKSYNC, ���̵�: ��) - p168
	Ǯ�� Ǯ������, å�� ����� ��ȿ��.
	���� Ʈ���� �̿��ؼ�(������ Ǯ����) Ǯ����,
	å�� ����Ž���� �̿��߱� ������ å�� �����ؾ���.
	���� �ڷ�� ������Ʈ ���Ͽ� ����. �������� ��Ʈ������.
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

