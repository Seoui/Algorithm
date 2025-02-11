#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//vector<double> dp(10001, 0.0f);
double MaxMulti(vector<double>& n)
{
	double result = n[1];
	size_t idx = n.size() - 1;
	for (size_t i = 1; i <= idx - 1; ++i) {
		double accum = n[i];
		for (size_t j = i + 1; j <= idx; ++j) {
			accum *= n[j];
			result = max(result, accum);
		}
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vector<double> nums;
	nums.push_back(0);
	int N;
	cin >> N;
	while (N--) {
		float n;
		cin >> n;
		nums.push_back(n);
	}

	printf("%.3lf", MaxMulti(nums));
	//cout << round(MaxMulti(nums) * 1000) / 1000 << '\n';
	system("pause");
	return 0;
}