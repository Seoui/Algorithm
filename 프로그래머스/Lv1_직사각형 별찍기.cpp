#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	int m;
	cin >> n >> m;
	

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			cout << '*';
		cout << '\n';
	}

	system("pause");
	return 0;
}