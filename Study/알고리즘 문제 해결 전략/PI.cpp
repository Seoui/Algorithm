#include "SeouiAlgorithm.h"
#include "PI.h"

PI::PI()
{
}

PI::~PI()
{
}

void PI::solution()
{
	cin >> testCase;
	while (testCase--)
	{
		cin >> N;
		result.push_back(memorize(0));
	}

	for (auto& r : result)
		cout << r << '\n';
}

int PI::classify(int a, int b)
{
	string M = N.substr(a, b - a + 1);
	if (M == string(M.size(), M[0])) return 1;
	bool progressive = true;
	for (size_t i = 0; i < M.size() - 1; ++i)
		if (M[i + 1] - M[i] != M[1] - M[0])
			progressive = false;
	if (progressive && abs(M[1] - M[0]) == 1)
		return 2;
	bool alternating = true;
	for (size_t i = 0; i < M.size(); ++i)
		if (M[i] != M[i % 2])
			alternating = false;
	if (alternating) return 4;
	if (progressive) return 5;
	return 10;
}

int PI::memorize(int begin)
{
	if (begin == N.size()) return 0;
	int& ret = cache[begin];
	if (ret != -1) return ret;
	ret = INF;
	for (size_t L = 3; L <= 5; ++L)
		if (begin + L <= N.size())
			ret = min(ret, memorize(begin + L) +
				classify(begin, begin + L - 1));

	return ret;
}
