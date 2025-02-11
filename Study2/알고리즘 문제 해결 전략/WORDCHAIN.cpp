#include "SeouiAlgorithm.h"
#include "WORDCHAIN.h"

void WORDCHAIN::makeGraph(const vector<string>& words)
{
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j)
			graph[i][j].clear();
	/*
		graph는 요소 하나하나가 vector<string> 타입임.
		따라서 graph는 3차원 배열로 볼 수 있음. graph[26][26][동적할당크기(string의 갯수)]
	*/
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	indegree = outdegree = vector<int>(26, 0);

	for (size_t i = 0; i < words.size(); ++i)
	{
		/*
			a = 단어의 처음 문자의 상대적 위치('a'의 위치가 0일때의 상대위치)
			b = 단어의 끝 문자의 상대적 위치
			graph[a][b] 는 vector<string> 타입이다.
		*/
		int a = words[i][0] - 'a';
		int b = words[i][words[i].size() - 1] - 'a';
		graph[a][b].push_back(words[i]);
		adj[a][b]++;
		outdegree[a]++;
		indegree[b]++;
	}
}

void WORDCHAIN::getEulerCircuit(int here, vector<int>& circuit)
{
	for(size_t there = 0; there < adj.size(); ++there)
		while (adj[here][there] > 0)
		{
			adj[here][there]--;
			getEulerCircuit(there, circuit);
		}
	circuit.push_back(here);
}

vector<int> WORDCHAIN::getEulerTrailOrCircuit()
{
	vector<int> circuit;
	for(int i =0; i<26; ++i)
		if (outdegree[i] == indegree[i] + 1)
		{
			getEulerCircuit(i, circuit);
			return circuit;
		}
	for(int i =0; i<26;++i)
		if (outdegree[i]) {
			getEulerCircuit(i, circuit);
			return circuit;
		}

	return circuit;
}

bool WORDCHAIN::checkEuler()
{
	int plus1 = 0, minus1 = 0;
	for (int i = 0; i < 26; ++i) {
		int delta = outdegree[i] - indegree[i];
		if (delta < -1 || delta > 1)  return false;
		if (delta == 1) plus1++;
		if (delta == -1) minus1++;
	}

	return (plus1 == 1 && minus1==1) || (plus1 == 0 && minus1 == 0);
}

string WORDCHAIN::solve(const vector<string>& words)
{
	makeGraph(words);
	if (!checkEuler()) return "IMPOSSIBLE";
	vector<int> circuit = getEulerTrailOrCircuit();
	if (circuit.size() != words.size() + 1) return "IMPOSSIBLE";

	reverse(circuit.begin(), circuit.end());
	string ret;
	for (size_t i = 1; i < circuit.size(); i++)
	{
		int a = circuit[i - 1], b = circuit[i];
		if (ret.size()) ret += " ";
		ret += graph[a][b].back();
		graph[a][b].pop_back();
	}

	return ret;
}

void WORDCHAIN::solution()
{
	cin >> testCase;
	while (testCase--)
	{
		cin >> numWord;
		for (int i = 0; i < numWord; ++i)
		{
			string word;
			cin >> word;
			words.push_back(word);
		}
		cout << solve(words) << '\n';
		words.clear();
	}
}
