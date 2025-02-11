#pragma once
#include <cstdio>
#include <algorithm>
#include <queue>
#define MAX_VTXS 16

class AdjMatGraph
{
protected:
	int size;
	char vertices[MAX_VTXS];
	int adj[MAX_VTXS][MAX_VTXS];
	bool visited[MAX_VTXS];
	int label[MAX_VTXS];

public:
	AdjMatGraph() { reset(); }
	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }

	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS; }

	void reset()
	{
		size = 0;
		for (int i = 0; i < MAX_VTXS; ++i)
			for (int j = 0; j < MAX_VTXS; ++j)
				setEdge(i, j, 0);
		std::fill(vertices, vertices + MAX_VTXS, 0);
		for(int i = 0; i < MAX_VTXS; ++i)
			std::fill(adj[i], adj[i] + MAX_VTXS, 0);
		resetVisited();
	}

	void resetVisited()
	{
		std::fill(visited, visited + MAX_VTXS, 0);
		std::fill(label, label + MAX_VTXS, 0);
	}

	bool isLinked(int u, int v) { return getEdge(u, v) != 0; }

	void DFS(int v)
	{
		visited[v] = true;
		printf("%c ", getVertex(v));
		for (int i = 0; i < size; ++i) {
			if (isLinked(v, i) && visited[i] == false)
				DFS(i);
		}
	}

	void labelDFS(int v, int color)
	{
		visited[v] = true;
		label[v] = color;
		for (int i = 0; i < size; ++i) {
			if (isLinked(v, i) && visited[i] == false)
				labelDFS(i, color);
		}
	}

	void findConnectedComponent()
	{
		int count = 0;
		for (int i = 0; i < size; ++i)
			if (visited[i] == false)
				labelDFS(i, ++count);
		printf("그래프 연결성분 개수 = %d\n", count);
		for (int i = 0; i < size; ++i)
			printf("%c=%d ", getVertex(i), label[i]);
		printf("\n");
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
			for (int i = 0; i < size; ++i) {
				if(isLinked(f, i) && visited[i] == false) {
					visited[i] = true;
					printf("%c ", getVertex(i));
					q.push(i);
				}
			}
		}
	}

	void insertVertex(char name)
	{
		if (!isFull())
			vertices[size++] = name;
		else
			printf("Error: 그래프 정점 개수 초과\n");
	}

	void insertEdge(int u, int v)
	{
		setEdge(u, v, 1);
		setEdge(v, u, 1);
	}

	void display(FILE* fp = stdout)
	{
		fprintf(fp, "%d\n", size);
		for (int i = 0; i < size; ++i) {
			fprintf(fp, "%c ", getVertex(i));
			for (int j = 0; j < size; ++j)
				fprintf(fp, " %3d", getEdge(i, j));
			fprintf(fp, "\n");
		}
	}

	void load(const char* filename)
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

	void store(const char* filename)
	{
		FILE* fp;
		fopen_s(&fp, filename, "w");
		if (fp != NULL) {
			display(fp);
			fclose(fp);
		}
	}
};