// c++ 6µî
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vector<int> title;
	int num = 0;
	size_t N;
	cin >> N;
	while (true) {
		if (num % 10 == 6) {
			if (num % 100 == 66) {
				if (num % 1000 == 666) {
					for (int i = 0; i < 1000; ++i)
						title.push_back(num * 1000 + i);
					if (title.size() > N) break;
					num++;
				}
				else {
					for (int i = 0; i < 100; ++i)
						title.push_back(num * 1000 + 600 + i);
					if (title.size() > N) break;
					num++;
				}
			}
			else {
				for (int i = 0; i < 10; ++i)
					title.push_back(num * 1000 + 660 + i);
				if (title.size() > N) break;
				num++;
			}
		}
		else {
			title.push_back(num * 1000 + 666);
			if (title.size() > N) break;
			num++;
		}
	}
	cout << title[N - 1] << '\n';
	return 0;
}