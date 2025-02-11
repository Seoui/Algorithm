#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

void CalculateStatistic(vector<int>& nums, vector<int>& count)
{
	int mean = 0;
	int median = 0;
	int mode = 0;
	int range = 0;

	// arithmetic mean
	double sum = accumulate(begin(nums), end(nums), 0);
	mean = static_cast<int>(round(sum / nums.size()));

	// median
	sort(begin(nums), end(nums));
	if (nums.size() % 2 == 0)
		median = (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2;
	else
		median = nums[nums.size() / 2];

	// mode
	if (nums.size() == 1)
		mode = nums[0];
	else {
		int countMode = 0;
		vector<int>::iterator maxNumCount = max_element(begin(count), end(count));
		for (auto& c : count)
			if (c == *maxNumCount)
				++countMode;
		if (countMode > 1) {
			int j = 0;
			for (size_t i = 0; i < count.size(); ++i) {
				if (count[i] == *maxNumCount)
					++j;
				if (j == 2) {
					mode = static_cast<int>(i) - 4000;
					break;
				}
			}
		}
		else if (countMode == 1) {
			mode = static_cast<int>(maxNumCount - begin(count)) - 4000;
		}
	}

	// range
	auto minmax = minmax_element(begin(nums), end(nums));
	range = *minmax.second - *minmax.first;

	cout << mean << '\n';
	cout << median << '\n';
	cout << mode << '\n';
	cout << range << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> nums;
	vector<int> count(8001, 0);
	int N;
	cin >> N;
	while (N--) {
		int n;
		cin >> n;
		nums.push_back(n);
		count[n + 4000] += 1;
	}
	CalculateStatistic(nums, count);
	system("pause");
	return 0;
}