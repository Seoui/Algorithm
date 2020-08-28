#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int time = 0;
	string inputStr;
	cin >> inputStr;
	for (size_t i = 0; i < inputStr.size(); ++i)
	{
		if (inputStr[i] == 'A' || inputStr[i] == 'B' || inputStr[i] == 'C')								
			time += 3;
		else if (inputStr[i] == 'D' || inputStr[i] == 'E' || inputStr[i] == 'F')						
			time += 4;
		else if (inputStr[i] == 'G' || inputStr[i] == 'H' || inputStr[i] == 'I')						
			time += 5;
		else if (inputStr[i] == 'J' || inputStr[i] == 'K' || inputStr[i] == 'L')						
			time += 6;
		else if (inputStr[i] == 'M' || inputStr[i] == 'N' || inputStr[i] == 'O')						
			time += 7;
		else if (inputStr[i] == 'P' || inputStr[i] == 'Q' || inputStr[i] == 'R' || inputStr[i] == 'S')	
			time += 8;
		else if (inputStr[i] == 'T' || inputStr[i] == 'U' || inputStr[i] == 'V')						
			time += 9;
		else if (inputStr[i] == 'W' || inputStr[i] == 'X' || inputStr[i] == 'Y' || inputStr[i] == 'Z')	
			time += 10;
	}

	cout << time << "\n";
	return 0;
}