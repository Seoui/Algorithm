#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int SubDn(int con)
{
	if (con < 10 && con >= 0)
		return con;
	int ret = 0;
	ret += con % 10;
	con = con / 10;
	ret += SubDn(con);

	return ret;
}

int Dn(int con)
{
	return con + SubDn(con);
}

int main()
{
	vector<int> ret;
	for (int i = 0; i < 10000; ++i)
		ret.push_back(Dn(i));
	sort(ret.begin(), ret.end());
	ret.erase(unique(ret.begin(), ret.end()), ret.end());

	vector<int>::iterator it = ret.begin();
	for (int i = 0; i < 10000; ++i)
	{
		if (*it != i)
			cout << i << "\n";
		if (*it == i)
			it++;
		if (it == ret.end())
			break;
	}
	return 0;
}