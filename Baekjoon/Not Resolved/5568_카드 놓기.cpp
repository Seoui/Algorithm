#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1 2 3 4
void PrintSubset(vector<int>& subset)
{
	cout << "(";
	for (auto& s : subset)
		cout << s << ", ";
	cout << ")\n";
	subset.clear();
}
// 1 2 12 1
// (1, 2) (1, 1) (1, 12) (2, 12) (2, 1)
// (1, 2) (1, 12) (1, 1) (2, 12) (2, 1) (12, 1)
// 6����
// C: (1, 2) (1, 3) (1, 4) (2, 3) (2, 4) (3, 4)
// �Ľ�Į�� �ﰢ�� nCk = n-1Ck-1 + n-1Ck
void Combination(vector<int>& subset, int n, int k) 
{
	if (k == 0) { PrintSubset(subset); return; }
	// smallest�� subset�� �� �����̴�(�ε����� �ƴϴ�)
	int smallest = subset.empty() ? 0 : subset.back() + 1;
	for (int next = smallest; next < n; ++next) {
		subset.push_back(next);
		Combination(subset, n, k - 1);
		subset.pop_back();
	}
}

// ���� �˰����� �̸� �ʱ�ȭ�� �迭�� ����Ѵ�.
// 12����
// P: (1, 2) (2, 1) (1, 3) (3, 1) (1, 4) (4, 1) (2, 3) (3, 2) (2, 4) (4, 2) (3, 4) (4, 3)
void Permutation(vector<int>& subset, int n, int k)
{	
	if (n == k) { PrintSubset(subset); return; }


}

// nHk = k+(n-1)Ck�̴�.  4H2 = 5C2 = 10����
// H:  (1, 2) (1, 3) (1, 4) (2, 3) (2, 4) (3, 4) (1, 1) (2, 2) (3, 3) (4, 4)
void CombinationR(vector<int>& cards, int k)
{

}

// n��k = n^k, 4^2 = 16����
// ��: (1, 2) (2, 1) (1, 3) (3, 1) (1, 4) (4, 1) (2, 3) (3, 2) (2, 4) (4, 2) 
//	  (3, 4) (4, 3) (1, 1) (2, 2) (3, 3) (4, 4)
void PermutationR(vector<int>& cards, int k)
{

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	/*
		n: ī�� ���� [4, 10]
		k: ������ ī�� ���� [2, 4]
		�ᱹ n������ k�� �̾Ƽ� ������ ������ ���
	*/
	int n, k;
	cin >> n >> k;
	vector<int> subset;
	/*
	vector<int> cards;
	
	while (n--) {
		int c;
		cin >> c;
		cards.push_back(c);
	}*/
	subset.push_back(1);
	subset.push_back(2);
	subset.push_back(3);
	subset.push_back(4);
	subset.push_back(5);

	do {
		for (auto& s : subset)
			cout << s << " ";
		cout << '\n';
	} while (next_permutation(begin(subset), end(subset)));
	/*
	Combination(subset, n, k);
	Permutation(subset, n, k);
	*/
	system("pause");
	return 0;
}