#include "SeouiAlgorithm.h"
#include "WORDCHAIN.h"

void WORDCHAIN::makeGraph(const vector<string>& words)
{
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j)
			graph[i][j].clear();
	/*
		graph�� ��� �ϳ��ϳ��� vector<string> Ÿ����.
		���� graph�� 3���� �迭�� �� �� ����. graph[26][26][�����Ҵ�ũ��(string�� ����)]
	*/
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	indegree = outdegree = vector<int>(26, 0);

	for (size_t i = 0; i < words.size(); ++i)
	{
		/*
			a = �ܾ��� ó�� ������ ����� ��ġ('a'�� ��ġ�� 0�϶��� �����ġ)
			b = �ܾ��� �� ������ ����� ��ġ
			graph[a][b] �� vector<string> Ÿ���̴�.
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
