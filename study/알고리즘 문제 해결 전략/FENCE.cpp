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

// h[left...right] �������� ã�Ƴ� �� �ִ� ���� ū �簢���� ���̸� ��ȯ�Ѵ�.
int FENCE::solve(int left, int right)
{
	// ���� ���: ���ڰ� �ϳ��ۿ� ���� ���
	if (left == right) return h[curCase][left];
	// [left,mid], [mid+1, right]�� �� �������� ������ �����Ѵ�.
	int mid = (left + right) / 2;
	// ������ ������ ��������
	int ret = max(solve(left, mid), solve(mid + 1, right));
	// �κ� ���� 3: �� �κп� ��� ��ġ�� �簢�� �� ���� ū ���� ã�´�.
	int lo = mid, hi = mid + 1;
	int height = min(h[curCase][lo], h[curCase][hi]);
	// [mid, mid+1]�� �����ϴ� �ʺ� 2�� �簢���� ����Ѵ�.
	ret = max(ret, height * 2);
	// �簢���� �Է� ��ü�� ���� ������ Ȯ���� ������.
	while (left < lo || hi < right)
	{
		// �׻� ���̰� �� ���� ������ Ȯ���Ѵ�.
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

		// Ȯ���� �� �簢���� ����
		ret = max(ret, height * (hi - lo + 1));
	}

	return ret;
}

/* ����, �ʹ� �����ϰ� Ǯ���� �ߴ� */
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
	// ���ĵǰ� �ߺ����� ����
	//curVec.erase(unique(curVec.begin(), curVec.end()), curVec.end());
	while (fenceHeight[curIdx].size() != 0)
	{
		//minHeight = *min_element(fenceHeight[curIdx].begin(), fenceHeight[curIdx].end());
		//if (k < curVec.size())
			//minHeight = curVec[k];
		minHeight = fenceHeight[curIdx][k];
		nfence = ContinuousFence(curIdx, minHeight, k); // �ش���̿����ؿ������������ǰ���
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