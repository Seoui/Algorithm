#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool MyLess(int a, int b)
{
	if (a < b)
		return true;
	else
		return false;
}

int main()
{
	vector<int> vec = { 5, 4, 3, 2, 1 };
	//sort(begin(vec), end(vec), MyLess);
	// �⺻ ���°� less��.
	next_permutation(begin(vec), end(vec));
	for (auto& a : vec)
		cout << a << " ";
	cout << endl;
	system("pause");
	return 0;
}