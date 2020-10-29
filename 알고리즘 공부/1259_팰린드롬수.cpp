#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string input;
	vector<string> v;
	while (true)
	{
		cin >> input;
		if (input == "0")
			break;
		v.push_back(input);
	}

	for (auto& ev : v)
	{
		string::iterator s = begin(ev);
		string::iterator e = end(ev) - 1;
		int error = 0;
		while ((s != end(ev)) && (e != begin(ev)))
		{
			if (*s == *e)
			{
				s++;
				e--;
			}
			else {
				error++;
				break;
			}
		}
		
		if (error)
			cout << "no" << '\n';
		else
			cout << "yes" << '\n';
	}
	return 0;
}