#pragma once
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>

class Node
{
protected:
	int id;
	Node* link;

public:
	Node(int i, Node* l = nullptr) : id(i), link(l) {}
	~Node() 
	{
		if (link != nullptr)
			delete link;
	}

	int getId() { return id; }
	Node* getLink() { return link; }
	void setLink(Node* l) { link = l; }
};

#define MAX_VTXS 32

class AdjListGraph
{
protected:
	int size;
	char vertices[MAX_VTXS];
	Node* adj[MAX_VTXS];
	bool visited[MAX_VTXS];
	int inDeg[MAX_VTXS];

public:
	AdjListGraph() : size(0) 
	{
		std::fill(vertices, vertices + MAX_VTXS, 0);
		std::fill(adj, adj + MAX_VTXS, nullptr);
		std::fill(visited, visited + MAX_VTXS, 0);
		std::fill(inDeg, inDeg + MAX_VTXS, 0);
	}
	~AdjListGraph() { reset(); }

	void reset()
	{
		for (int i = 0; i < size; ++i)
			if (adj[i] != nullptr) delete adj[i];
		size = 0;
	}

	void resetVisited()
	{
		std::fill(visited, visited + MAX_VTXS, 0);
	}

	bool isLinked(int u, int v)
	{
		for (Node* p = adj[u]; p != nullptr; p = p->getLink())
			if (p->getId() == v)
				return true;
		
		return false;
	}

	void DFS(int v)
	{
		visited[v] = true;
		printf("%c ", getVertex(v));

		for (Node* p = adj[v]; p != nullptr; p = p->getLink())
			if (visited[p->getId()] == false)
				DFS(p->getId());
	}

	void BFS(int v)
	{
		visited[v] = true;
		printf("%c ", getVertex(v));
		std::queue<int> q;
		q.push(v);
		while (!q.empty()) {
			int f = q.front();
			q.pop();
			for (Node* p = adj[f]; p != nullptr; p = p->getLink()) {
				int id = p->getId();
				if (visited[id] == false) {
					visited[id] = true;
					printf("%c ", getVertex(id));
					q.push(id);
				}
			}
		}
	}

	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_VTXS; }
	char getVertex(int i) { return vertices[i]; }

	void insertVertex(char val)
	{
		if (!isFull()) {
			vertices[size] = val;
			adj[size++] = nullptr;
		}
		else
			printf("Error: 그래프 정점 개수 초과\n");
	}

	void insertEdge(int u, int v)
	{
		adj[u] = new Node(v, adj[u]);
		adj[v] = new Node(u, adj[v]);
	}

	void insertDirEdge(int u, int v)
	{
		adj[u] = new Node(v, adj[u]);
	}

	void topoSort()
	{
		for (int i = 0; i < size; ++i)
			inDeg[i] = 0;
		for (int i = 0; i < size; ++i) {
			Node* node = adj[i];
			while (node != nullptr) {
				inDeg[node->getId()]++;
				node = node->getLink();
			}
		}

		std::stack<int> s;
		for (int i = 0; i < size; ++i)
			if (inDeg[i] == 0)
				s.push(i);

		while (!s.empty()) {
			int w = s.top();
			s.pop();
			printf(" %c ", getVertex(w) + 65);
			Node* node = adj[w];
			while (node != nullptr) {
				int u = node->getId();
				inDeg[u]--;
				if (inDeg[u] == 0)
					s.push(u);
				node = node->getLink();
			}
		}
		printf("\n");
	}

	void display()
	{
		printf("%d\n", size);
		for (int i = 0; i < size; ++i) {
			printf("%c  ", getVertex(i));
			for (Node* v = adj[i]; v != nullptr; v = v->getLink())
				printf("  %c", getVertex(v->getId()));
			printf("\n");
		}
	}

	Node* adjacent(int v) { return adj[v]; }

	void load(const char *filename) 
	{
		FILE* fp;
		fopen_s(&fp, filename, "r");
		int gbg = 0;
		if (fp != NULL) {
			int n;
			gbg = fscanf_s(fp, "%d", &n);
			for (int i = 0; i < n; ++i) {
				char str[80];
				gbg = fscanf_s(fp, "%s", str, 80);
				insertVertex(str[0]);
				for (int j = 0; j < n; ++j) {
					int val;
					gbg = fscanf_s(fp, "%d", &val);
					if (val != 0)
						insertEdge(i, j);
				}
			}
			fclose(fp);
		}
	}
};