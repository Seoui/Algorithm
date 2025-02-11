#include "SeouiAlgorithm.h"

JLIS::JLIS()
{
	for (int i = 0; i < 101; ++i)
		for (int j = 0; j < 100; ++j)
			cache[i][j] = -1;
}

JLIS::~JLIS()
{
}

int JLIS::lis(const vector<int>& A)
{
	if (A.empty()) return 0;
	int ret = 0;
	for (size_t i = 0; i < A.size(); ++i)
	{
		vector<int> B;
		for (size_t j = i + 1; j < A.size(); ++j)
			if (A[i] < A[j])
				B.push_back(A[j]);
		ret = max(ret, 1 + lis(B));
	}
	return ret;
}

int JLIS::jlis(int indexA, int indexB)
{
	int& ret = cache[indexA + 1][indexB + 1];
	if (ret != -1) return ret;
	ret = 2;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long maxElement = max(a, b);
	for (int nextA = indexA + 1; nextA < n; ++nextA)
		if (maxElement < A[nextA])
			ret = max(ret, jlis(nextA, indexB) + 1);
	for (int nextB = indexB + 1; nextB < m; ++nextB)
		if (maxElement < B[nextB])
			ret = max(ret, jlis(indexA, nextB) + 1);
	return ret;
}

void JLIS::solution()
{
	cout << jlis(-1, -1) << "\n";
}
