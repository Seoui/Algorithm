#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> map =
{
	{"black" , 0},
	{"brown" , 1},
	{"red"	 , 2},
	{"orange", 3},
	{"yellow", 4},
	{"green" , 5},
	{"blue"	 , 6},
	{"violet", 7},
	{"grey"	 , 8},
	{"white" , 9}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string f, s, t;
	cin >> f >> s >> t;
	int fv = map.find(f)->second;
	int sv = map.find(s)->second;
	long long tv = (long long)pow(10, map.find(t)->second);
	string fs = to_string(fv) + to_string(sv);
	long long ret = stoi(fs) * tv;
	cout << ret << '\n';
	system("pause");
	return 0;
}