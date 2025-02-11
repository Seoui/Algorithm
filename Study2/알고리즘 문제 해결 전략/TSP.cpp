#include "SeouiAlgorithm.h"

TSP::TSP()
{
}

TSP::~TSP()
{
}

double TSP::shortestPath(vector<int>& path, vector<bool>& visited, double currentLength)
{
	if (path.size() == nCity)
		return currentLength + dist[path[0]][path.back()];
	double ret = INFINITY;
	for (int next = 0; next < nCity; next++)
	{
		if (visited[next]) continue;
		int here = path.back();
		path.push_back(next);
		visited[next] = true;
		double cand = shortestPath(path, visited, currentLength + dist[here][next]);
		ret = min(ret, cand);
	
		visited[next] = false;
		path.pop_back();
	}

	return ret;
}

void TSP::solution()
{
	cin >> nCity;
	for (int i = 0; i < nCity; i++)
	{
		visited.push_back(0);
		path.push_back(0);
	}
	cout << shortestPath(path, visited, currentLength) << "\n";
}
