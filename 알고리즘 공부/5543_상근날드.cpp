#include <iostream>
using namespace std;

int main()
{
	int hambug[3];
	int drink[2];

	cin >> hambug[0] >> hambug[1] >> hambug[2];
	cin >> drink[0] >> drink[1];

	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < 2; ++i)
		{
			if (hambug[i] > hambug[i + 1])
			{
				int temp;
				temp = hambug[i];
				hambug[i] = hambug[i + 1];
				hambug[i + 1] = temp;
			}
		}
	}

	if (drink[0] > drink[1])
	{
		int temp;
		temp = drink[0];
		drink[0] = drink[1];
		drink[1] = temp;
	}

	cout << hambug[0] + drink[0] - 50 << '\n';

	return 0;
}