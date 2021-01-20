#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void GetMaxHeight(vector<int>& th, int M) 
{
	sort(begin(th), end(th), greater<int>());
	int max = th[0];
	int mid = max / 2;
	int min = 1;
	while (min <= max) {
		long long sumLength = 0;
		for (auto& t : th) {
			if (t > mid)
				sumLength += t - mid;
			else break;
		}
		if (sumLength > M) {
			min = mid + 1;
			mid = (max + min) / 2;
		}
		else if (sumLength < M) {
			max = mid - 1;
			mid = (max + min) / 2;
		}
		else break;
	}
	cout << mid << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> treesH;
	int N, M;
	cin >> N >> M;
	while (N--) {
		int h;
		cin >> h;
		treesH.push_back(h);
	}
	GetMaxHeight(treesH, M);
	return 0;
}