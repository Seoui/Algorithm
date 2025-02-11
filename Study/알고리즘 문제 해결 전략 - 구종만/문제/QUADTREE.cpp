#include "SeouiAlgorithm.h"

QUADTREE::QUADTREE()
{
}

QUADTREE::~QUADTREE()
{
}

void QUADTREE::solution()
{
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		string inputStr;
		cin >> inputStr;
		inputString.push_back(inputStr);
	}

	for(int i = 0; i < testCase; i++)
	{
		string::iterator it = inputString[i].begin();
		retString.push_back(reverse(it));
		cout << retString[i] << endl;
	}
}

string QUADTREE::reverse(string::iterator & it)
{
	char head = *it;
	++it;
	if (head == 'b' || head == 'w')
		return string(1, head);
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);

	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

