#pragma once
#include "AdjMatGraph.h"
#include <vector>
#include <set>
#include <tuple>
using namespace std;
#define INF 9999
#define MAX_ELEMENT 16

class VertexSets
{
	int parent[MAX_VTXS];
	int nSets;

public:
	VertexSets(int n) : nSets(n)
	{
		std::fill(parent, parent + nSets, -1);
	}

	bool isRoot(int i) { return parent[i] < 0; }

	int findSet(int v)
	{
		while (!isRoot(v))
			v = parent[v];
		return v;
	}

	void unionSets(int s1, int s2)
	{
		parent[s1] = s2;
		nSets--;
	}
};

class HeapNode
{
	int key;
	int v1;
	int v2;
public:
	HeapNode() : key(0), v1(0), v2(0) {}
	HeapNode(int k, int u, int v) : key(k), v1(u), v2(v) {}
	void setKey(int k, int u, int v) { key = k; v1 = u; v2 = v; }
	int getKey() { return key; }
	int getV1() { return v1; }
	int getV2() { return v2; }
};

class MinHeap
{
	HeapNode node[MAX_ELEMENT];
	int size;

public:
	MinHeap() :size(0) {}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT; }

	HeapNode& getParent(int i) { return node[i / 2]; }
	HeapNode& getLeft(int i) { return node[i * 2]; }
	HeapNode& getRight(int i) { return node[i * 2 + 1]; }

	void insert(int key, int u, int v)
	{
		if (isFull()) return;
		int i = ++size;

		while (i != 1 && key < getParent(i).getKey()) {
			node[i] = getParent(i);
			i /= 2;
		}
		node[i].setKey(key, u, v);
	}

	HeapNode remove()
	{
		if (isEmpty()) return HeapNode{};
		HeapNode item = node[1];
		HeapNode last = node[size--];
		int parent = 1;
		int child = 2;
		while (child <= size) {
			if (child < size && getLeft(parent).getKey() > getRight(parent).getKey())
				child++;
			if (last.getKey() <= node[child].getKey()) break;

			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;
		return item;
	}

	HeapNode find() { return node[1]; }
};

class WGraph : public AdjMatGraph
{
public:
	void insertEdge(int u, int v, int weight)
	{
		if (weight > INF) weight = INF;
		setEdge(u, v, weight);
	}

	bool hasEdge(int i, int j) { return (getEdge(i, j) < INF); }

	void load(const char* filename)
	{
		FILE* fp;
		fopen_s(&fp, filename, "r");
		if (fp != nullptr) {
			int n;
			fscanf_s(fp, "%d", &n);
			for (int i = 0; i < n; ++i) {
				char str[80];
				int val;
				fscanf_s(fp, "%s", str, 80);
				insertVertex(str[0]);
				for (int j = 0; j < n; ++j) {
					fscanf_s(fp, "%d", &val);
					insertEdge(i, j, val);
				}
			}
			fclose(fp);
		}
	}

	void Kruskal()
	{
		vector<tuple<int, int, int>> heap;
		for (int i = 0; i < size - 1; ++i)
			for (int j = i + 1; j < size; ++j)
				if (hasEdge(i, j))
					heap.push_back(make_tuple(getEdge(i, j), i, j));

		sort(begin(heap), end(heap), greater<>{});

		VertexSets set(size);
		int edgeAccepted = 0;
		while (edgeAccepted < size - 1) {
			auto e = heap.back();
			heap.pop_back();
			int uset = set.findSet(get<1>(e));
			int vset = set.findSet(get<2>(e));
			if (uset != vset) {
				printf("간선 추가 : %c - %c (비용:%d)\n",
					getVertex(get<1>(e)), getVertex(get<2>(e)), get<0>(e));
				set.unionSets(uset, vset);
				edgeAccepted++;
			}
		}
		/*
		MinHeap heap;
		for (int i = 0; i < size - 1; ++i)
			for (int j = i + 1; j < size; ++j)
				if (hasEdge(i, j))
					heap.insert(getEdge(i, j), i, j);

		VertexSets set(size);
		int edgeAccepted = 0;
		while (edgeAccepted < size - 1) {
			HeapNode e = heap.remove();
			int uset = set.findSet(e.getV1());
			int vset = set.findSet(e.getV2());
			if (uset != vset) {
				printf("간선 추가 : %c - %c (비용:%d)\n",
					getVertex(e.getV1()), getVertex(e.getV2()), e.getKey());
				set.unionSets(uset, vset);
				edgeAccepted++;
			}
		}*/
	}

	void Prim(int s)
	{
		bool selected[MAX_VTXS];
		int dist[MAX_VTXS];
		for (int i = 0; i < size; ++i) {
			dist[i] = INF;
			selected[i] = false;
		}
		dist[s] = 0;

		for (int i = 0; i < size; ++i) {
			int u = getMinVertex(selected, dist);
			selected[u] = true;

			if (dist[u] == INF) return;

			printf("%c ", getVertex(u));
			for (int v = 0; v < size; ++v)
				if (getEdge(u, v) != INF)
					if (!selected[v] && getEdge(u, v) < dist[v])
						dist[v] = getEdge(u, v);
		}
		printf("\n");
	}

	int getMinVertex(bool* selected, int* dist)
	{
		int minv = 0;
		int mindist = INF;

		for (int v = 0; v < size; ++v)
			if (!selected[v] && dist[v] < mindist) {
				mindist = dist[v];
				minv = v;
			}
		return minv;
	}

private:
	int dist[MAX_VTXS];
	bool found[MAX_VTXS];

public:
	int chooseVertex()
	{
		int min = INF;
		int minpos = -1;
		for (int i = 0; i < size; ++i)
			if (dist[i] < min && !found[i]) {
				min = dist[i];
				minpos = i;
			}
		return minpos;
	}

	void ShortestPath(int start)
	{
		for (int i = 0; i < size; ++i) {
			dist[i] = getEdge(start, i);
			found[i] = false;
		}

		found[start] = true;
		dist[start] = 0;

		for (int i = 0; i < size; ++i) {
			printf("Step%2d:", i + 1);
			printDistance();

			int u = chooseVertex();
			found[u] = true;
			for (int w = 0; w < size; ++w) {
				if (found[w] == false)
					if (dist[u] + getEdge(u, w) < dist[w])
						dist[w] = dist[u] + getEdge(u, w);
			}
		}
	}

	void printDistance()
	{
		for (int i = 0; i < size; ++i)
			printf("%5d", dist[i]);
		printf("\n");
	}

private:
	int A[MAX_VTXS][MAX_VTXS];

public:
	void ShortestPathFloyed()
	{
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				A[i][j] = getEdge(i, j);

		for (int k = 0; k < size; ++k) {
			for (int i = 0; i < size; ++i)
				for (int j = 0; j < size; ++j)
					if (A[i][k] + A[k][j] < A[i][j])
						A[i][j] = A[i][k] + A[k][j];
			printA();
		}
	}

	void printA()
	{
		printf("===================================\n");
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (A[i][j] == INF) printf(" INF ");
				else printf("%4d ", A[i][j]);
			}
			printf("\n");
		}
	}
};