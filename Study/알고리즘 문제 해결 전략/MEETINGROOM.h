#pragma once

class MEETINGROOM
{
public:
	MEETINGROOM();
	~MEETINGROOM();

	int scc(int here);
	vector<int> tarjanSCC();
	bool disjoint(const pair<int, int>& a, const pair<int, int>& b);
	void makeGraph(const vector<pair<int, int>>& meetings);
	vector<int> solve2SAT();

private:
	vector<vector<int>> adj;
	vector<int> sccId;
	vector<int> discovered;
	stack<int> st;
	int sccCounter, vertexCounter;
};

