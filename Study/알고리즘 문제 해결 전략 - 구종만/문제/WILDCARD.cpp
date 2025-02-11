#include "SeouiAlgorithm.h"

WILDCARD::WILDCARD()
{
}

WILDCARD::~WILDCARD()
{
}

void WILDCARD::solution()
{
	cin >> testCase;
	while(testCase--)
	{
		vector<string> str;
		cin >> wildcardPattern >> numFile;
		str.push_back(move(wildcardPattern));
		for (int i = 0; i < numFile; ++i)
		{
			cin >> fileName;
			str.push_back(move(fileName));
		}
		strs.push_back(move(str));
	}
	
	// 여기서 해결한다.
	vector<string> result = MatchPattern(strs);

	for (auto& r : result)
		cout << r << endl;
}

vector<string> WILDCARD::MatchPattern(vector<vector<string>>& strs)
{
	size_t testSize = strs.size();
	vector<string> ret;
	for (size_t i = 0; i < testSize; ++i)
	{
		size_t numFile = strs[i].size();
		// string pattern = strs[i][0];
		for (size_t j = 1; j < numFile; ++j)
		{
			// string fileName = strs[i][1];
			if(CompareString(strs[i][0], strs[i][j]))
				ret.push_back(strs[i][j]);
		}
	}

	return ret;
}

bool WILDCARD::CompareString(const string & str1, const string & str2)
{
	size_t pos = 0;
	while (pos < str1.size() && pos < str2.size() &&
		(str1[pos] == '?' || str1[pos] == str2[pos]))
		++pos;

	// 패턴문자열의 끝에 도달했다. pos는 두 문자열의 길이의 최솟값임
	// 따라서 의미하는 바는 '*'가 하나도 없다.
	if (pos == str1.size())
		return pos == str2.size();
	
	// 위에서 종료가 안되었다. 패턴문자열의 길이가 더 작다
	// 따라서 분명 적어도 한개의 '*'를 포함 할 것이다.
	if (str1[pos] == '*')
	{
		// '*'는 몇개의 문자로 이루어 질지 모른다.
		// skip은 '*'에 대응하는 문자의 개수가 될 것이다.
		for (int skip = 0; pos + skip <= str2.size(); ++skip)
			// '*' 포함 이전 문자들을 자른 문자열('*' 이후 문자열)과
			// '*' 에 해당하는 위치의 비교문자열(2번째 문자열)
			// 즉 두번째 문자열에서 '*'에 대응하는 문자부터
			// skip까지, 즉 skip이 얼마나 큰지 모르지만 끝까지 계속 검사함.
			// 어느하나라도 참이 된다면 true를 리턴
			if (CompareString(str1.substr(pos + 1), str2.substr(pos + skip)))
				return true;
	}
	
	return false;
}

bool WILDCARD::matchMemoized(size_t w, size_t s, const string & str1, const string & str2)
{
	int& ret = cache[w][s];
	if (ret != -1) return ret;
	while (s < str2.size() && w < str1.size() &&
		(str1[w] == '?' || str1[w] == str2[s]))
	{
		++w;
		++s;
	}

	if (w == str1.size()) return ret = (s == str2.size());
	if (str1[w] == '*')
		for (int skip = 0; skip + s <= str2.size(); ++skip)
			if (matchMemoized(w + 1, s + skip, str1, str2))
				return ret = 1;

	return ret = 0;
}


