#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

ll maxLength(vector<unsigned int>& length, int N, ll max, ll mid, ll min)
{
	if (min > max) return mid;
	int sum = 0;
	for (size_t i = 0; i < length.size(); ++i)
		sum += static_cast<int>(length[i] / mid);
	if (sum >= N)
		min = mid + 1;
	else
		max = mid - 1;
	mid = (max + min) / 2;
	return maxLength(length, N, max, mid, min);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<unsigned int> length;
	int K, N;
	cin >> K >> N;
	while (K--) {
		unsigned int l;
		cin >> l;
		length.push_back(l);
	}

	ll max = 0;
	for (size_t i = 0; i < length.size(); ++i)
		max += length[i];
	max /= N;
	ll min = 1;
	ll mid = (max + min) / 2;
	cout << maxLength(length, N, max, mid, min) << '\n';
	return 0;
}