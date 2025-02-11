#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool AreFriends(pair<int, int>& a, pair<int, int>& b)
{
	return a.first != b.first &&
		a.first != b.second &&
		a.second != b.first &&
		a.second != b.second;
}

int main()
{
	vector<pair<int, int>> pairs;
	int testCase;
	int student;
	int numPair;
	cin >> testCase;
	while (testCase--)
	{
		cin >> student >> numPair;
		int pair_first;
		int pair_second;
		for (int i = 0; i < numPair; ++i)
		{
			cin >> pair_first >> pair_second;
			pairs.push_back(make_pair(pair_first, pair_second));
		}
	}

	// �Է� ģ���� first ������������, first�� ������ second ������������ ����.
	sort(begin(pairs), end(pairs),
		[](pair<int, int> p1, pair<int, int> p2) {
		if (p1.first < p2.first) return true;
		else if (p1.first == p2.first) return p1.second < p2.second;
		else return false;
	});
	
	int result = 0;
	for(int k = 0; k< numPair; ++k)
	{
		for (int i = 1; i < numPair; ++i) 
		{
			if (AreFriends(pairs[k], pairs[i]))
			{
				// ��� �ٸ��ٸ� ģ�� ���� �� ����.
				int s_f = i;
				for (int j = i + 1; j < numPair; ++j)
				{
					if (AreFriends(pairs[s_f], pairs[j]) && AreFriends(pairs[k], pairs[j]))
					{
						// ù�� °�� �ι�°���� �ٸ� ģ�� ������ �ִ°���.
						result++;
					}
				}
			
			}
		}
	}
	

	for (auto& i : pairs)
		cout << i.first << ", " << i.second << endl;

	cout << "result : " << result << endl;
	system("pause");
	return 0;
}

/*
	1. �ϳ� �̴´�.
	2. ������ ģ�� �ְ� �ϳ��� ���Ѵ�.
	3. ���ϴٰ� ���� �ٸ� ģ�� ���� ������ �� ģ���� �̴´�.
	4. �ٽ� ������ ģ�� �ְ� �ϳ��� ���Ѵ�.
*/