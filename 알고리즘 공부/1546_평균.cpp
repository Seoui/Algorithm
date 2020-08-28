#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<float> a;
	float input;
	float max = 0;
	float sum = 0;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (max < input)
			max = input;
		a.push_back(input);
	}

	for (auto& element : a)
		sum += element / max * 100;

	cout << sum / a.size() << '\n';

	return 0;
}
