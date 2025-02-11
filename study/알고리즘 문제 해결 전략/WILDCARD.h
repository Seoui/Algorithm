#pragma once

/*
	8.2 ����: ���ϵ�ī�� (���� ID: WILDCARD, ���̵�: ��) - p218
	�޸������̼��� Ȱ���� matchMemoized �Լ��� ����
*/

class WILDCARD
{
public:
	WILDCARD();
	~WILDCARD();

	void solution();
	vector<string> MatchPattern(vector<vector<string>>& strs);
	bool CompareString(const string& str1, const string& str2);
	bool matchMemoized(size_t w, size_t s, const string & str1, const string & str2);

private:
	int testCase = 0;				// �׽�Ʈ ���̽�, �ִ� 10������ �ڿ���
	int numFile;					// ���� ����, �ִ� 50������ �ڿ���
	string wildcardPattern;			// ���ϵ� ī�� ���� W
	string fileName;				// ���ϸ�
	vector<vector<string>> strs;
	int cache[101][101];			// �޸������̼��� ���� ĳ��

};

