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


// 분할 정복
int solveDQ(vector<int>& h, int left, int right)
{
	// 기저 사례: 판자가 하나밖에 없는 경우
	if(left == right) return h[left];
	// [left, mid], [mid+1, right]의 두 구간으로 문제를 분할한다.
	int mid = (left + right) / 2;
	// 문제의 (1),(2)경우. 한 쪽에 최대넓이의 직사각형이 존재할 때,
	int ret = max(solveDQ(h, left, mid), solveDQ(h, left+1, right));
	
	// (3)경우. 최대넓이 직사각형이 양쪽에 걸쳐 있을 때,
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);
	// [mid, mid+1]만 포함하는 너비 2인 사각형을 고려한다.
	ret = max(ret, height * 2);
	 
	/*	사각형이 입력 전체를 덮을 때까지 확장한다.
		lo가 left보다 작거나 같을 때 그리고 hi가 right보다 크거나 같을 때 while문 종료.
		즉 lo와 hi가 범위를 둘 다 동시에 양쪽 범위를 벗어나면 반복문 종료. */
	while(left < lo || hi < right) {
		/*  hi가 right보다 작으면서 lo == left 이거나 h[lo-1] < h[hi + 1]인 경우
			여기서 lo == left 조건은 왼쪽으로는 이미 다 확장했다는 의미.
			이 때, h[lo]를 0으로 봐도 무방하다. */
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
		int N;	// Fence의 개수
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