#pragma once

/*
	6.7 예제: Traveling Sales-man Problem, TSP - p165
	예제이고 마땅한 테스트 케이스 주어지 않음.
	해결 못함
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

