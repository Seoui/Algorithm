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
// 6가지
// C: (1, 2) (1, 3) (1, 4) (2, 3) (2, 4) (3, 4)
// 파스칼의 삼각형 nCk = n-1Ck-1 + n-1Ck
void Combination(vector<int>& subset, int n, int k) 
{
	if (k == 0) { PrintSubset(subset); return; }
	// smallest는 subset에 들어갈 숫자이다(인덱스가 아니다)
	int smallest = subset.empty() ? 0 : subset.back() + 1;
	for (int next = smallest; next < n; ++next) {
		subset.push_back(next);
		Combination(subset, n, k - 1);
		subset.pop_back();
	}
}

// 순열 알고리즘만이 미리 초기화한 배열을 사용한다.
// 12가지
// P: (1, 2) (2, 1) (1, 3) (3, 1) (1, 4) (4, 1) (2, 3) (3, 2) (2, 4) (4, 2) (3, 4) (4, 3)
void Permutation(vector<int>& subset, int n, int k)
{	
	if (n == k) { PrintSubset(subset); return; }


}

// nHk = k+(n-1)Ck이다.  4H2 = 5C2 = 10가지
// H:  (1, 2) (1, 3) (1, 4) (2, 3) (2, 4) (3, 4) (1, 1) (2, 2) (3, 3) (4, 4)
void CombinationR(vector<int>& cards, int k)
{

}

// nΠk = n^k, 4^2 = 16가지
// Π: (1, 2) (2, 1) (1, 3) (3, 1) (1, 4) (4, 1) (2, 3) (3, 2) (2, 4) (4, 2) 
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
		n: 카드 개수 [4, 10]
		k: 선택할 카드 개수 [2, 4]
		결국 n개에서 k를 뽑아서 순열을 만들라는 얘기
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