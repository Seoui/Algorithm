#pragma once

/*
	8.7 ����: ������ �ܿ�� (���� ID: PI, ���̵�: ��) - p239

*/
class PI
{
public:
	PI();
	~PI();

	void solution();
	int classify(int a, int b);
	int memorize(int begin);

private:
	/*
		��� ���ڰ� ���� ��							- ���̵� 1
		���ڰ� 1�� ���� �����ϰų� ���� ������ ��	- ���̵� 2
		�� ���� ���ڰ� �����ư��� ��Ÿ�� ��			- ���̵� 4
		���ڰ� ���� ������ �̷� ��					- ���̵� 5
		�� ���� ��� ���							- ���̵� 10
	*/
	int testCase = 0;		// �׽�Ʈ ���̽�, �ִ� 50�� �ڿ���
	string N;				// ����, 8�ڸ� �̻� 10000�ڸ� ������ �ڿ�����
							// (���� 8�� �̻� 10000�� ������ ���ڿ�)
	const int INF = 987654321;
	int cache[10002];
	vector<int> result;
};

