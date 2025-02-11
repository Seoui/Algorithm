#include "SeouiAlgorithm.h"
#include "FENCE.h"
 
FENCE::FENCE()
{
}

FENCE::~FENCE()
{
}

void FENCE::solution()
{
	cin >> testCase;
	for (int i = 0; i < testCase;i++)
	{
		curCase = i;
		cin >> nfence;
		vector<int> vf;
		for (int j = 0; j < nfence;j++)
		{
			int f;
			cin >> f;
			vf.push_back(f);
		}
		h.push_back(vf);
		//ret.push_back(bruteForce(fenceHeight[i]));
		ret.push_back(solve(0,6));
	}

	int a;
	a = 5;
}

int FENCE::bruteForce(const vector<int>& h)
{
	int ret = 0;
	int N = h.size();

	for (int left = 0; left < N; left++)
	{
		int minHeight = h[left];
		for (int right = left; right < N; right++)
		{
			minHeight = min(minHeight, h[right]);
			ret = max(ret, (right - left + 1) * minHeight);
		}
	}
	return ret;
}

// h[left...right] 구간에서 찾아낼 수 있는 가장 큰 사각형의 넓이를 반환한다.
int FENCE::solve(int left, int right)
{
	// 기저 사례: 판자가 하나밖에 없는 경우
	if (left == right) return h[curCase][left];
	// [left,mid], [mid+1, right]의 두 구간으로 문제를 분할한다.
	int mid = (left + right) / 2;
	// 분할한 문제를 각개격파
	int ret = max(solve(left, mid), solve(mid + 1, right));
	// 부분 문제 3: 두 부분에 모두 걸치는 사각형 중 가장 큰 것을 찾는다.
	int lo = mid, hi = mid + 1;
	int height = min(h[curCase][lo], h[curCase][hi]);
	// [mid, mid+1]만 포함하는 너비 2인 사각형을 고려한다.
	ret = max(ret, height * 2);
	// 사각형이 입력 전체를 덮을 때까지 확장해 나간다.
	while (left < lo || hi < right)
	{
		// 항상 높이가 더 높은 쪽으로 확장한다.
		if (hi < right && (lo == left || h[curCase][lo - 1] < h[curCase][hi + 1]))
		{
			++hi;
			height = min(height, h[curCase][hi]);
		}
		else
		{
			--lo;
			height = min(height, h[curCase][lo]);
		}

		// 확장한 후 사각형의 넓이
		ret = max(ret, height * (hi - lo + 1));
	}

	return ret;
}

/* 실패, 너무 복잡하게 풀려고 했다 */
/*
void FENCE::solution()
{
	cin >> testCase;
	for (int i = 0; i < testCase;i++)
	{
		cin >> nfence;
		vector<int> vf;
		for (int j = 0; j < nfence;j++)
		{
			int f;
			cin >> f;
			vf.push_back(f);
		}
		fenceHeight.push_back(vf);
		ret.push_back(RectArea(i));
	}

	int a;
	a = 5;
}

int FENCE::RectArea(int i)
{
	int curIdx = i;
	int k = 0;
	int maxArea = numeric_limits<int>::min();
	int minHeight = 0;
	vector<int> curVec = fenceHeight[curIdx];
	sort(curVec.begin(), curVec.end());
	// 정렬되고 중복없는 벡터
	//curVec.erase(unique(curVec.begin(), curVec.end()), curVec.end());
	while (fenceHeight[curIdx].size() != 0)
	{
		//minHeight = *min_element(fenceHeight[curIdx].begin(), fenceHeight[curIdx].end());
		//if (k < curVec.size())
			//minHeight = curVec[k];
		minHeight = fenceHeight[curIdx][k];
		nfence = ContinuousFence(curIdx, minHeight, k); // 해당높이에대해연속적인판자의개수
		if (minHeight * nfence > maxArea)
			maxArea = minHeight * nfence;
		else
			maxArea = maxArea;
		//fenceHeight[curIdx].erase(min_element(fenceHeight[curIdx].begin(), fenceHeight[curIdx].end()));
		k++;
	}

	return maxArea;
}

int FENCE::ContinuousFence(int curIdx, int minHeight, int k)
{
	int nContinous = 0;
	int minHeightIdx = find(fenceHeight[curIdx].begin(), fenceHeight[curIdx].end(), minHeight) - fenceHeight[curIdx].begin();
	vector<int>::iterator curValue = find(fenceHeight[curIdx].begin(), fenceHeight[curIdx].end(), minHeight);
	int maxpX = distance(curValue, fenceHeight[curIdx].end());//6
	int maxnX = -distance(fenceHeight[curIdx].begin(), curValue);//-1

	for (int pdx = 1; pdx < maxpX; pdx++)
	{
		if (fenceHeight[curIdx][minHeightIdx + pdx] >= minHeight)
			nContinous++;
		else
			break;
	}
	for (int ndx = -1; ndx >= maxnX; ndx--)
	{
		if (fenceHeight[curIdx][minHeightIdx + ndx] >= minHeight)
			nContinous++;
		else
			break;
	}

	return nContinous + 1;
}
*/