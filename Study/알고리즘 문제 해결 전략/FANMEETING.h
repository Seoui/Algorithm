#pragma once
/*
	7.6 ����: �ҹ��� (���� ID: FANMEETING, ���̵�: ��) - p201
	karatsuba ���� �˰����� �ٽ��̴�.
	���� �����ִ� ���� Ʋ���� �ƴ�����, �ð��ʰ���.
	�ð��� ���̱� ���ؼ��� karatsuba ���� �˰����� �ٽ� �ѹ� ����
	-p183 ��.
*/
class FANMEETING
{
public:
	FANMEETING();
	~FANMEETING();

	void solution();
	int Hug(string&, string&);
	string ShiftString(string& str);

private:
	int testCase = 0;			// �׽�Ʈ ���̽�, �ִ� 20�� �ڿ���
	vector<int> ret;
};

