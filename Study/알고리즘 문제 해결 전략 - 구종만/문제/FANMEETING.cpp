#include "SeouiAlgorithm.h"
#include "FANMEETING.h"
FANMEETING::FANMEETING()
{
}

FANMEETING::~FANMEETING()
{
}

void FANMEETING::solution()
{
	cin >> testCase;
	while (testCase--)
	{
		string inputIdol;
		cin >> inputIdol;

		string inputFan;
		cin >> inputFan;

		ret.push_back(Hug(inputIdol, inputFan));
	}

	for (auto& r : ret)
		cout << r << endl;
}

int FANMEETING::Hug(string& idolGender, string& fanGender)
{
	int nIdol = idolGender.size();
	int nFan = fanGender.size();
	int nWaiting = nFan - nIdol;
	int nHug = 0;
	string str = fanGender;

	for (int i = 0; i <= nWaiting; ++i)
	{
		int count = 0;
		for (int j = 0; j < nIdol; ++j)
		{
			// idol ������ ���ڶ�� ��ζ� ���˰���.
			if (idolGender[j] == 'F')
				++count;
			else if (idolGender[j] == 'M' && str[j] == 'F')
				++count;
		}
		// ���ÿ� ������ ����
		if (count == nIdol)
			nHug++;

		str = ShiftString(str);
	}
	return nHug;
}

string FANMEETING::ShiftString(string & str)
{
	string ret = str.substr(1);
	return ret;
}
