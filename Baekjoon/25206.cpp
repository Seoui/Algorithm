#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, float> t = { {"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5}, {"B0", 3.0}, {"C+", 2.5}, {"C0", 2.0}, {"D+", 1.5}, {"D0", 1.0}, {"F", 0.0} };
	float sum{}, total{};
	for (int i = 0; i < 20; ++i) {
		string a, b;
		float c;
		cin >> a >> c >> b;
		if (b.compare("P") != 0) {
			sum += c * t[b];
			total += c;
		}
	}
	cout << fixed;
	cout.precision(6);
	cout << sum / total << '\n';
	return 0;
}