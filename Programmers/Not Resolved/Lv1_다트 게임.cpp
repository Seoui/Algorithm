#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

int solution(string d) 
{
	/*	1µî ÄÚµå

	stringstream ss(dartResult);

    int sum[3] = { 0, 0, 0 };
    int options[3] = { 1, 1, 1 };
    for (int i = 0; i < 3; i++) {
        int score;
        char bonus;
        char option;

        ss >> score;

        bonus = ss.get();
        option = ss.get();

        if (option != '*' && option != '#') {
            ss.unget();
        }

        switch (bonus) {
        case 'S':
            sum[i] += pow(score, 1);
            break;
        case 'D':
            sum[i] += pow(score, 2);
            break;
        case 'T':
            sum[i] += pow(score, 3);
            break;
        default:
            break;
        }

        switch (option) {
        case '*':
            if (i > 0 && options[i - 1]) options[i - 1] *= 2;
            options[i] *= 2;
            break;
        case '#':
            options[i] = -options[i];
            break;
        default:
            break;
        }
    }

    return sum[0] * options[0] + sum[1] * options[1] + sum[2] * options[2];
	
	*/
	int answer = 0;
	stack<int> stk;
	string num = "";
	for (int i = 0; i < d.size(); ++i) {
		if (isdigit(d[i])) {
			num += d[i];
			if (!isdigit(d[i + 1])) {
				stk.push(stoi(num));
				num = "";
			}
		}
		else if (d[i] == 'S') {}
		else if (d[i] == 'D') {
			int t = stk.top();
			t = t * t;
			stk.pop();
			stk.push(t);
		}
		else if (d[i] == 'T') {
			int t = stk.top();
			t = t * t * t;
			stk.pop();
			stk.push(t);
		}
		else if (d[i] == '#') {
			int t = stk.top();
			t = -t;
			stk.pop();
			stk.push(t);
		}
		else if (d[i] == '*') {
			int t = stk.top(); 
			t *= 2;
			stk.pop();
			int inner = 0;
			if (!stk.empty()) {
				inner = stk.top();
				inner *= 2;
				stk.pop();
				stk.push(inner);
			}
			stk.push(t);
		}
	}

	while(!stk.empty()) {
		answer += stk.top();
		stk.pop();
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << solution("1S2D*3T") << endl;
	cout << solution("1D2S#10S") << endl;
	cout << solution("1D2S0T") << endl;
	cout << solution("1S*2T*3S") << endl;
	cout << solution("1D#2S*3S") << endl;
	cout << solution("1T2D3D#") << endl;
	cout << solution("1D2S3T*") << endl;
	cout << solution("1S2D*3T*") << endl;
	cout << solution("1S2D3T*") << endl;
	system("pause");
	return 0;
}