#pragma once

class WORDCHAIN
{
public:
	WORDCHAIN() = default;
	~WORDCHAIN() = default;

	void makeGraph(const vector<string>& words);
	void getEulerCircuit(int here, vector<int>& circuit);
	vector<int> getEulerTrailOrCircuit();
	bool checkEuler();
	string solve(const vector<string>& words);
	void solution();

private:
	vector<vector<int>> adj;
	vector<string> graph[26][26];
	vector<int> indegree, outdegree;
	int testCase;
	int numWord;
	vector<string> words;
};

