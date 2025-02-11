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

	// 입력 친구쌍 first 오름차순으로, first가 같으면 second 오름차순으로 정렬.
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
				// 모두 다르다면 친구 맺을 수 있음.
				int s_f = i;
				for (int j = i + 1; j < numPair; ++j)
				{
					if (AreFriends(pairs[s_f], pairs[j]) && AreFriends(pairs[k], pairs[j]))
					{
						// 첫번 째랑 두번째랑도 다른 친구 조합이 있는거임.
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
	1. 하나 뽑는다.
	2. 나머지 친구 쌍과 하나씩 비교한다.
	3. 비교하다가 완전 다른 친구 쌍이 있으면 그 친구를 뽑는다.
	4. 다시 나머지 친구 쌍과 하나씩 비교한다.
*/