#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// mine
int solveMine(vector<int>& h)
{
	int ret = 0;
	for (int i = 0; i < h.size(); ++i) {
		int area = h[i];
		for (int j = i + 1; j < h.size(); ++j) {
			if (h[j] >= h[i])
				area += h[i];
			else
				break;
		}
		for (int j = i - 1; j >= 0; --j) {
			if (h[j] >= h[i])
				area += h[i];
			else break;
		}
		ret = max(ret, area);
	}
	return ret;
}

// Ku
int solveKu(const vector<int>& h)
{
	int ret = 0;
	int N = (int)h.size();
	for (int left = 0; left < N; ++left) {
		int minHeight = h[left];
		for (int right = left; right < N; ++right) {
			minHeight = min(minHeight, h[right]);
			ret = max(ret, (right - left + 1) * minHeight);
		}
	}
	return ret;
}


// ���� ����
int solveDQ(vector<int>& h, int left, int right)
{
	// ���� ���: ���ڰ� �ϳ��ۿ� ���� ���
	if(left == right) return h[left];
	// [left, mid], [mid+1, right]�� �� �������� ������ �����Ѵ�.
	int mid = (left + right) / 2;
	// ������ (1),(2)���. �� �ʿ� �ִ������ ���簢���� ������ ��,
	int ret = max(solveDQ(h, left, mid), solveDQ(h, left+1, right));
	
	// (3)���. �ִ���� ���簢���� ���ʿ� ���� ���� ��,
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);
	// [mid, mid+1]�� �����ϴ� �ʺ� 2�� �簢���� ����Ѵ�.
	ret = max(ret, height * 2);
	 
	/*	�簢���� �Է� ��ü�� ���� ������ Ȯ���Ѵ�.
		lo�� left���� �۰ų� ���� �� �׸��� hi�� right���� ũ�ų� ���� �� while�� ����.
		�� lo�� hi�� ������ �� �� ���ÿ� ���� ������ ����� �ݺ��� ����. */
	while(left < lo || hi < right) {
		/*  hi�� right���� �����鼭 lo == left �̰ų� h[lo-1] < h[hi + 1]�� ���
			���⼭ lo == left ������ �������δ� �̹� �� Ȯ���ߴٴ� �ǹ�.
			�� ��, h[lo]�� 0���� ���� �����ϴ�. */
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> h;
	int C;
	cin >> C;
	while (C--) {
		int N;	// Fence�� ����
		cin >> N;
		for (int i = 0; i < N; ++i) {
			int height;
			cin >> height;
			h.push_back(height);
		}
		cout << solveDQ(h, 0, (int)h.size() - 1) << '\n';
		h.clear();
	}
	system("pause");
	return 0;
}