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
	
	// ���⼭ �ذ��Ѵ�.
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

	// ���Ϲ��ڿ��� ���� �����ߴ�. pos�� �� ���ڿ��� ������ �ּڰ���
	// ���� �ǹ��ϴ� �ٴ� '*'�� �ϳ��� ����.
	if (pos == str1.size())
		return pos == str2.size();
	
	// ������ ���ᰡ �ȵǾ���. ���Ϲ��ڿ��� ���̰� �� �۴�
	// ���� �и� ��� �Ѱ��� '*'�� ���� �� ���̴�.
	if (str1[pos] == '*')
	{
		// '*'�� ��� ���ڷ� �̷�� ���� �𸥴�.
		// skip�� '*'�� �����ϴ� ������ ������ �� ���̴�.
		for (int skip = 0; pos + skip <= str2.size(); ++skip)
			// '*' ���� ���� ���ڵ��� �ڸ� ���ڿ�('*' ���� ���ڿ�)��
			// '*' �� �ش��ϴ� ��ġ�� �񱳹��ڿ�(2��° ���ڿ�)
			// �� �ι�° ���ڿ����� '*'�� �����ϴ� ���ں���
			// skip����, �� skip�� �󸶳� ū�� ������ ������ ��� �˻���.
			// ����ϳ��� ���� �ȴٸ� true�� ����
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


