#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int c;
	int n;
	float point;
	vector<float> a;
	vector<float> higherThanAverage; //백분율
	cin >> c;
	for (int i = 0; i < c; i++) // 케이스 개수
	{
		float sum = 0;
		float average = 0;
		int hta = 0; // 평균보다 높은 점수 개수
		cin >> n; // 학생수 
		for (int j = 0; j < n; j++)
		{
			cin >> point; // 각 학생의 점수
			a.push_back(point);
			sum += point;
		}

		average = sum / (float)a.size(); //평균 구한거임

		for (auto& element : a)
		{
			if (average < element)
				hta++;	// 평균보다 높은 사람 수 구하기
		}

		higherThanAverage.push_back((float)hta / (float)a.size() * 100);
		a.clear();
	}

	for (auto& i : higherThanAverage)
	{
		cout << fixed;
		cout.precision(3);
		cout << i << "%" << '\n';
	}

	return 0;
}