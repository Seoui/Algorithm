#include <iostream>
#include <cmath>
#include <numeric>
using namespace std;

long long solution(int w, int h) 
{
	long long answer = 0;
	long long W = w;
	long long H = h;
	long long amount = W * H;
	long long GCD = gcd(W, H);
	long long col = W + H - GCD;
	return answer = amount - col;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	solution(4, 4);
	system("pause");
	return 0;
}