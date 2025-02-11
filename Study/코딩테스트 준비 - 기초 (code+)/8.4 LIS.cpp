#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 완전 탐색 알고리즘
int lis(const vector<int>& A)
{
	if (A.empty()) return 0;
	int ret = 0;
	for (int i = 0; i < A.size(); ++i) {
		vector<int> B;
		for (int j = i + 1; j < A.size(); ++j) {
			if (A[i] < A[j])
				B.push_back(A[j]);
		}
		ret = max(ret, 1 + lis(B));
	}
	return ret;
}

// 동적 계획법 알고리즘 (1) - O(n^2)
int n2;
int cache2[100], S2[100];
int lis2(int start)
{
	int& ret = cache2[start];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = start + 1; next < n2; ++next)
		if (S2[start] < S2[next])
			ret = max(ret, lis2(next) + 1);
	return ret;
}

// 동적 계획법 알고리즘 (2) - O(n^2)
int n3;
int cache3[101], S3[100];
int lis3(int start)
{
	int& ret = cache3[start + 1];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = start + 1; next < n3; ++next)
		if (start == -1 || S3[start] < S3[next])
			ret = max(ret, lis3(next) + 1);
	return ret;
}

// 동적 계획법 알고리즘 (3) - O(nlgk)
int main()
{
	int result = lis({ 3, 2, 1, 7, 5, 4, 2, 6 });
	cout << result << '\n';
	system("pause");
	return 0;
}