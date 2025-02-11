#pragma once

/*
	7.2 ����: ���� Ʈ�� ������ (���� ID: QUADTREE, ���̵�: ��) - p189
*/
struct ��ġ
{
	string str[4];
	string wholeStr;
};

class QUADTREE
{
public:
	QUADTREE();
	~QUADTREE();

	void solution();
	string reverse(string::iterator& it);
	

private:
	int testCase = 0;	// �ִ� 50�� �ڿ���
	int edge = 0;		// �� ���� ����, �ִ� 20�� ���� �ƴ� ����
	vector<string> inputString;
	vector<string> retString;
};

