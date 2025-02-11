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
	/*	parent �迭�� �θ� ���ҷ� ���´�. �ε����� ������ ��Ÿ����.
	*	parent�� ���Ұ� -1�̸� ��Ʈ��� �ǹ̴�. 
	*	nSets�� ������ ���� */
	int parent[MAX_VTXS];
	int nSets;

public:
	// ������ ó������ ��� ������ ������ �����̱� ������ nSets�� ������ ������ ����.
	VertexSets(int n) : nSets(n)
	{
		std::fill(parent, parent + nSets, -1);
	}

	bool isRoot(int i) { return parent[i] < 0; }
	
	// ��ȯ ���� �ش� ������ ��Ʈ ����̴�.
	int findSet(int v)
	{
		while (!isRoot(v))
			v = parent[v];
		return v;
	}

	/* �Ķ���� s1�� s2�� ������ �ǹ��Ѵ�. ��, Ư�� ������ ��Ʈ��带 �ǹ�
	*  s1������ s2�� ���δ�. s1������ ��Ʈ��尡 ���� s2�� �θ�� ���´�. */
	void unionSets(int s1, int s2)
	{
		parent[s1] = s2;
		nSets--;
	}
};

/* ������ ������ ���ؼ� �������� ���� �˰����� ����� �� �ִ�.
*  ���⼭�� �ּ� ���� ����� �� ������ ����Ѵ�. */
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

	/*	1. heap���ٰ� �������� �ִ´�.(�ڵ����� ���ĵȴ�)
	*	2. ������ ������ŭ ������ �����
	*	3. edgeAccepted ������ ó���� ������ �����̴�. ������ size-1�� ���� ũ�ų� �������� while�� ����
	*	   �ֳĸ� �׷������� MST�� ��Ȯ�ϰ� ������ ���� - 1�� ��ŭ�� ������ �ֱ� �����̴�.
	*	4. while������ ������ �ٷ� �ּ� ����ġ�� ������. �� ����ġ�� �� ������ ������ ����̹Ƿ�, 
	*	   HeapNode���� �� ������ Ȯ���� �� �ִ�. �� ������ ������ Ȯ���ؼ�
	*	4-1. �� ������ ������ �ٸ��ٸ�
	*		 ����Ŭ�� �������� �ʴ´�. MST�� �߰��Ѵ�. �׸��� �� ������ ��ģ��.
	*	4-2. �� ������ ������ ���ٸ�
	*		 ����Ŭ�� �����Ѵ�. ���� */
	void Kruskal()
	{
		// Ʃ���� key, ����1, ����2 ����
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
				printf("���� �߰� : %c - %c (���:%d)\n",
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
				printf("���� �߰� : %c - %c (���:%d)\n",
					getVertex(e.getV1()), getVertex(e.getV2()), e.getKey());
				set.unionSets(uset, vset);
				edgeAccepted++;
			}
		}*/
	}

	void Prim(int s)
	{
		/*	selected�迭�� ������ MST�� ���ԵǾ�����?
		*	dist�迭�� �ش� �������� ������� �˷��� ���� ����� �Ÿ��� �����Ѵ�.
		*	��, s�κ��� Ư�� ���������� �Ÿ��� ����.*/
		bool selected[MAX_VTXS];
		int dist[MAX_VTXS];
		// �ʱ�ȭ
		for (int i = 0; i < size; ++i) {
			dist[i] = INF;
			selected[i] = false;
		}
		// �ڱ� �ڽ��̹Ƿ� �Ÿ��� 0
		dist[s] = 0;

		// ������ ������ŭ �ݺ�
		for (int i = 0; i < size; ++i) {
			/*	���� ������ �ּ� ����. ó������ �׻� 0�� ��ȯ�Ѵ�. 
			*	ó������ �˷��� �Ÿ��� ���� ����. 
			*	�� ��° ��ȸ���ʹ� ������Ʈ�� �Ÿ��� �ֱ� ������
			*	���� ����� ������ ���������� ��������.*/
			int u = getMinVertex(selected, dist);

			selected[u] = true;
			// u�� MST�� ����Ǿ� ���� �ʴ�.
			if (dist[u] == INF) return;
			// ���� ����� �� �ϳ� ���(ó������ �ڱ� �ڽ�)
			printf("%c ", getVertex(u));
			/*	��� ������ ��ȸ�ϸ鼭, ���� ������ ����� ������ ã�´�.
			*	���� ���� ������ ����� ���� ������ ������ ���̰� INF��� ����Ǿ� ���� �ʴٴ� ��.
			*	INF�� �ƴ϶�� ����Ǿ� �ִٴ� ���̴�. �� ����
			*	����� �� ������ ���õǾ����� �ʾҰ� ���� ���� ���̰� �˷��� ���̺��� �۴ٸ�
			*	���̸� �� ª�� ���̷� ������Ʈ ���ش�. �̰��� �ش� ������ ����� ��� ������ ���� �����Ѵ�.
			*	���� ���⼭ �ش� ������ selected ������ �ʴ� ���� �ָ�����. */
			for (int v = 0; v < size; ++v)
				if (getEdge(u, v) != INF)
					if (!selected[v] && getEdge(u, v) < dist[v])
						dist[v] = getEdge(u, v);
		}
		printf("\n");
	}

	// ������� �˷��� �������� �Ÿ��� �ּ��� ������ ��ȯ
	int getMinVertex(bool* selected, int* dist)
	{
		int minv = 0;
		int mindist = INF;
		// ��� ������ ��ȸ�ϸ鼭
		for (int v = 0; v < size; ++v)
			/*	���� ���� ���õǾ����� �ʾҰ�, v�������� �Ÿ��� ����(ó������ �����̰�, ���ķδ� �ٸ� ���������� �Ÿ���)���� �۴ٸ�
			*	�� �Ÿ��� v�������� �ּҰŸ���� ���� mindist�� ����
			*	minv�� �ּҰŸ��� ���� ������.
			*	�Ʒ� if���� for���� ���鼭 ���� �� ������ �� �ִ�.
			*	���������� for���� �������� ������� �˷��� ��� ������ �Ÿ��� ���� ����� ������ �Ÿ��� ���ϰԵȴ�.*/
			if (!selected[v] && dist[v] < mindist) {
				mindist = dist[v];
				minv = v;
			}
		// ���������� ������ �ּҰŸ� ����
		return minv;
	}

private:
	// dist�迭�� ���Ҵ� �����������κ��� � ���������� �ּҰŸ�
	// found�迭�� ���Ҵ� ���� ���� v�κ����� �ִ� ��ΰ� �̹� �߰ߵ� �������� ����
	// �������� �߰ߵǾ��ٸ� true
	int dist[MAX_VTXS];
	bool found[MAX_VTXS];

public:
	// �湮���� ���� ������ �߿��� �ִ� ��� �Ÿ��� ���� ���� ������ ã�� ��ȯ
	// �켱���� ť�� �ٲٸ� �� ������ ������ �� ����
	int chooseVertex()
	{
		int min = INF;
		int minpos = -1;
		// ��� ������ ��ȸ
		for(int i = 0; i < size; ++i)
			/*	������� �߰ߵ� ���� ������ �Ÿ� �� �ּڰ��� ã�´�.
			*	���� ���� �˷��� �������� �Ÿ��� ������ �߰ߵ� �������� �Ÿ����� �۰�,
			*	�� ������ ���� ���� S�� �߰����� �ʾҴٸ�
			*	�ּڰ��� min�� ������Ʈ �ϰ�, �ִ� ��� ������ minpos�� ���� */
			if (dist[i] < min && !found[i]) {
				min = dist[i];
				minpos = i;
			}
		// ���������� ��� ������ ��ȸ�ϸ鼭 �ִ� ��� �Ÿ��� ���� ���� ������ ���Ѵ�.
		return minpos;
	}

	void ShortestPath(int start)
	{
		// �ʱ�ȭ
		for (int i = 0; i < size; ++i) {
			dist[i] = getEdge(start, i);
			found[i] = false;
		}

		// ���� ������ �ٷ� ���� S�� �ִ´�.
		found[start] = true;
		// �ڱ� �ڽŰ��� �Ÿ� 0
		dist[start] = 0;

		// ��� ������ ��ȸ�ϸ鼭
		for (int i = 0; i < size; ++i) {
			printf("Step%2d:", i + 1);
			// ���� �������κ��� ���� i������ �Ÿ� ���
			printDistance();
			// ���� �������κ��� ���������� ����� ������ �� �ּ� ��θ� ���� ������ ��ȯ
			int u = chooseVertex();
			// �� ���� �߰��߰� ���� S�� �߰�
			found[u] = true;
			// �ٽ� ��� ���� ��ȸ�ϸ鼭 ������ ���Ӱ� S�� �߰��� ���� u�� ���� �ٲ� �ּ� ��θ� ������Ʈ
			for (int w = 0; w < size; ++w) {
				// ���� S�� ���Ե��� ���� �����̶��
				if (found[w] == false)
					/*	length(start, u) + length(u, w) < length(start, w)
					*	�� ������������ u�� ���� w�� ���� ��ο�, ������������ ���������� w�� ���� ��θ� ��
					*	���� �۴ٸ� ������Ʈ ���� ũ�ٸ� �ƹ��͵� ���Ѵ�. */
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
		// �迭 �ʱ�ȭ
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				A[i][j] = getEdge(i, j);

		// k�� i���� j�������� ����� �������̴�. 0~k���� �����
		/*	�׷��ϱ� ���� i���� ���� j�� ���� ��θ� ���Ҳ���, ó������ k=0 �̹Ƿ�, ���� 0�� 
		*	���İ��� ���������� ������ ��� ���ؼ� �ּ� ��θ� ã�´�.
		*	�� ������ �׷����� �ִ� ��� ���� i���� ��� �� ���� j�� ���� ��θ� ã�� ��������. (������ k=0�̹Ƿ� 0�� ���İ��ų� �ƴϰų�)
		*	�� ���� k=1�� �Ǹ� �̹� k=0�϶��� ���� ������ �Ÿ��� �� ���������Ƿ�(���� ������ ������� ���� ������ ���� �� �ִ�, ����� ���̴� INF�� �ǰ���), 
		*	�̰��� ������� ���� i���� j�� ���µ� ���� 1�� ���İ��� �ƴϸ� ���������� ���� ����ؼ� �����Ѵ�. 
		*	���⼭ i���� j�� ���� ���̴� �� k=0�϶� �ּ� ��η� ������Ʈ �Ǿ���(���� ������ ���� �ȵǼ� INF�ϼ��� �ִ�).
		*	�� ������ �ݺ��ϸ� ���������� ��� �������� ��� ���������� �ּ� ��θ� ���� �� �ְ� �ȴ�. */
		for (int k = 0; k < size; ++k){
			for (int i = 0; i < size; ++i)
				for (int j = 0; j < size; ++j)
					/*	k ������ ������ ����Ͽ� �ִ� ��θ� ���ϴµ�
					*	���� i �������� j �������� ���µ� k�� ���ļ� ���� ��ΰ� i���� j�� ���� ���� ��κ��� �۴ٸ�
					*	if���� �����Ѵ�(���̵ȴ�). ���ο� �ּ� ��θ� ã�� ���̹Ƿ� �� �Ÿ��� ������Ʈ �Ѵ�. */
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