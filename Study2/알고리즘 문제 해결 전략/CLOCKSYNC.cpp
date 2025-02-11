#include "SeouiAlgorithm.h"

CLOCKSYNC::CLOCKSYNC()
{
	// switch 0
	SwitchLinkClock[0][0] = true;
	SwitchLinkClock[0][1] = true;
	SwitchLinkClock[0][2] = true;
	// switch 1
	SwitchLinkClock[1][3] = true;
	SwitchLinkClock[1][7] = true;
	SwitchLinkClock[1][9] = true;
	SwitchLinkClock[1][11] = true;
	// switch 2
	SwitchLinkClock[2][4] = true;
	SwitchLinkClock[2][10] = true;
	SwitchLinkClock[2][14] = true;
	SwitchLinkClock[2][15] = true;
	// switch 3
	SwitchLinkClock[3][0] = true;
	SwitchLinkClock[3][4] = true;
	SwitchLinkClock[3][5] = true;
	SwitchLinkClock[3][6] = true;
	SwitchLinkClock[3][7] = true;
	// switch 4
	SwitchLinkClock[4][6] = true;
	SwitchLinkClock[4][7] = true;
	SwitchLinkClock[4][8] = true;
	SwitchLinkClock[4][10] = true;
	SwitchLinkClock[4][12] = true;
	// switch 5
	SwitchLinkClock[5][0] = true;
	SwitchLinkClock[5][2] = true;
	SwitchLinkClock[5][14] = true;
	SwitchLinkClock[5][15] = true;
	// switch 6
	SwitchLinkClock[6][3] = true;
	SwitchLinkClock[6][14] = true;
	SwitchLinkClock[6][15] = true;
	// switch 7
	SwitchLinkClock[7][4] = true;
	SwitchLinkClock[7][5] = true;
	SwitchLinkClock[7][7] = true;
	SwitchLinkClock[7][14] = true;
	SwitchLinkClock[7][15] = true;
	// switch 8
	SwitchLinkClock[8][1] = true;
	SwitchLinkClock[8][2] = true;
	SwitchLinkClock[8][3] = true;
	SwitchLinkClock[8][4] = true;
	SwitchLinkClock[8][5] = true;
	// switch 9
	SwitchLinkClock[9][3] = true;
	SwitchLinkClock[9][4] = true;
	SwitchLinkClock[9][5] = true;
	SwitchLinkClock[9][9] = true;
	SwitchLinkClock[9][13] = true;
}


CLOCKSYNC::~CLOCKSYNC()
{
}

void CLOCKSYNC::Wind(int nSwitch)
{
	for (int i = 0; i < 16; i++)
	{
		if (SwitchLinkClock[nSwitch][i])
			clockArray[i] = (clockArray[i] + 1) % 4;
	}
	count++;
}

int CLOCKSYNC::WindClock()
{
	if (clockArray[8] != clockArray[12])
		return -1;
	while (clockArray[8] != 0)
		Wind(4);
	while (clockArray[11] != 0)
		Wind(1);
	while (clockArray[13] != 0)
		Wind(9);

	if (clockArray[9] != clockArray[13] &&
		clockArray[9] != clockArray[11])
		return -1;
	while (clockArray[6] != 0)
		Wind(3);
	while (clockArray[10] != 0)
		Wind(2);
	while (clockArray[7] != 0)
		Wind(7);
	while (clockArray[5] != 0)
		Wind(8);
	while (clockArray[1] != 0)
		Wind(0);

	if (clockArray[0] != clockArray[2])
		return -1;
	while (clockArray[0] != 0)
		Wind(5);

	if (clockArray[14] != clockArray[15])
		return -1;
	while (clockArray[3] != 0)
		Wind(6);

	return count;
}

void CLOCKSYNC::solution()
{
	cin >> testCase;
	while (testCase--)
	{
		for (int i = 0; i < 16; i++)
		{
			cin >> nClock;
			clockArray[i] = nClock;
		}
		cout << WindClock() << "\n";
		count = 0;
	}
}
