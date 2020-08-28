#include <iostream>
using namespace std;

int main()
{
	int hambug[3];

	cin >> hambug[0] >> hambug[1] >> hambug[2];

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

	cout << hambug[1] << '\n';
	return 0;
}