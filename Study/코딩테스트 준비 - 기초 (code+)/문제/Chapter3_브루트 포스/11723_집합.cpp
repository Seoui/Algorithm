#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int S = 0;
	int M;
	cin >> M;
	while (M--) {
		string input;
		int num = 0;
		cin >> input;
		if (input != "all" && input != "empty")
			cin >> num;
		num -= 1;
		if (input == "add") 
			S |= (1 << num);
		else if(input == "remove")
			S &= ~(1 << num);
		else if (input == "check") {
			if (S & (1 << num)) cout << 1 << '\n';// ÀÖÀ½;
			else cout << 0 << '\n';
		}
		else if (input == "toggle")
			S ^= (1 << num);
		else if (input == "all")
			S = (1 << 20) - 1;
		else if (input == "empty")
			S = 0;
	}
	return 0;
}