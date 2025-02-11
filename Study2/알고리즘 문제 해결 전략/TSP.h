#pragma once

/*
	6.7 ����: Traveling Sales-man Problem, TSP - p165
	�����̰� ������ �׽�Ʈ ���̽� �־��� ����.
	�ذ� ����
*/
class TSP
{
public:
	TSP();
	~TSP();
	
	double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength);
	void solution();

private:

	int nCity = 0;
	double currentLength = 0;
	double dist[10][10] = { 0, };
	vector<int> path;
	vector<bool> visited;
};

