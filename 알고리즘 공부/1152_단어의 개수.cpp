#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<string> strs;
	stringstream stream1;
	string inputStr;
	string word;
	getline(cin, inputStr);
	stream1.str(inputStr);
	while (stream1 >> word)
		strs.push_back(word);
	cout << strs.size() << "\n";

	return 0;
}