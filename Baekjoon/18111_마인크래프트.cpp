#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const int dt = 2;//destroyBlockTime
static const int st = 1;//stackBlockTime

void Bulldoze(vector<vector<int>>& land, int B, int maxHeight) 
{
	int maxFloor = 0;
	int minTime = 987654321;

	for(int f = maxHeight; f >= 0; --f){
		int blocks = B;
		int bulldozeTime = 0;
		for (size_t i = 0; i < land.size(); ++i) {
			for (size_t j = 0; j < land[0].size(); ++j) {
				if (land[i][j] < f) { //½×±â
					blocks -= f - land[i][j];
					bulldozeTime += st * (f - land[i][j]);
				}
				else if (land[i][j] > f) {//Á¦°Å
					blocks += land[i][j] - f;
					bulldozeTime += dt * (land[i][j] - f);
				}
			}
		}
		if (blocks >= 0 && minTime > bulldozeTime){
			minTime = bulldozeTime;
			maxFloor = f;
		}
	}
	cout << minTime << " " << maxFloor << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	vector<int> w;
	vector<vector<int>> land;
	int N, M, B, maxHeight = 0;
	cin >> N >> M >> B;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j){
			int h;
			cin >> h;
			w.push_back(h);
			maxHeight = max(maxHeight, h);
		}
		land.push_back(w);
		w.clear();
	}
	Bulldoze(land, B, maxHeight);	
	return 0;
}