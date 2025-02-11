#pragma once
/*
	7.4 ����: ��Ÿ�� �߶󳻱� (���� ID: FENCE, ���̵�: ��) - p195
*/
class FENCE
{
public:
	FENCE();
	~FENCE();

	void solution();

	// O(n^2) �˰���
	int bruteForce(const vector<int>& h);
	// ���� ���� �˰���
	int solve(int left, int right);

private:
	int curCase = 0;
	int testCase = 0;		// �׽�Ʈ���̽�, �ִ� 50�� �ڿ���
	int nfence = 0;			// ���ڰ���, �ִ� 20000�� �ڿ���
	vector<int> ret;		// �ִ� ���簢���� ũ��
	vector<vector<int>> h;	// �� ������ ����, �ִ� 10000�� �ڿ���
	/* ����
	int RectArea(int i);
	int ContinuousFence(int curIdx, int minHeight, int k);
private:
	int testCase = 0;			// �׽�Ʈ���̽�, �ִ� 50�� �ڿ���
	int nfence = 0;				// ���ڰ���, �ִ� 20000�� �ڿ���
	vector<vector<int>> fenceHeight;	// �� ������ ����, �ִ� 10000�� �ڿ���
	vector<int> ret;			// �ִ� ���簢���� ũ��
	vector<int>::iterator it;
	*/
};

