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
	/*	parent 배열은 부모를 원소로 갖는다. 인덱스가 정점을 나타낸다.
	*	parent의 원소가 -1이면 루트라는 의미다. 
	*	nSets는 집합의 개수 */
	int parent[MAX_VTXS];
	int nSets;

public:
	// 어차피 처음에는 모든 정점이 고유한 집합이기 때문에 nSets는 정점의 개수와 같다.
	VertexSets(int n) : nSets(n)
	{
		std::fill(parent, parent + nSets, -1);
	}

	bool isRoot(int i) { return parent[i] < 0; }
	
	// 반환 값은 해당 집합의 루트 노드이다.
	int findSet(int v)
	{
		while (!isRoot(v))
			v = parent[v];
		return v;
	}

	/* 파라미터 s1과 s2는 집합을 의미한다. 즉, 특정 집합의 루트노드를 의미
	*  s1집합을 s2에 붙인다. s1집합의 루트노드가 이제 s2를 부모로 갖는다. */
	void unionSets(int s1, int s2)
	{
		parent[s1] = s2;
		nSets--;
	}
};

/* 간선의 정렬을 위해서 여러가지 정렬 알고리즘을 사용할 수 있다.
*  여기서는 최소 힙을 사용한 힙 정렬을 사용한다. */
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

	/*	1. heap에다가 간선들을 넣는다.(자동으로 정렬된다)
	*	2. 정점의 개수만큼 집합을 만든다
	*	3. edgeAccepted 변수는 처리한 간선의 개수이다. 개수가 size-1개 보다 크거나 같아지면 while문 종료
	*	   왜냐면 그래프에서 MST는 정확하게 정점의 개수 - 1개 만큼의 간선이 있기 때문이다.
	*	4. while문으로 들어오면 바로 최소 가중치를 꺼낸다. 이 가중치는 두 정점의 간선의 비용이므로, 
	*	   HeapNode에서 두 정점도 확인할 수 있다. 두 정점의 집합을 확인해서
	*	4-1. 두 정점의 집합이 다르다면
	*		 사이클이 존재하지 않는다. MST에 추가한다. 그리고 두 집합을 합친다.
	*	4-2. 두 정점의 집합이 같다면
	*		 사이클이 존재한다. 무시 */
	void Kruskal()
	{
		// 튜플은 key, 정점1, 정점2 순서
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
		/*	selected배열은 정점이 MST에 포함되었는지?
		*	dist배열은 해당 정점까지 현재까지 알려진 가장 가까운 거리를 저장한다.
		*	즉, s로부터 특정 정점까지의 거리를 저장.*/
		bool selected[MAX_VTXS];
		int dist[MAX_VTXS];
		// 초기화
		for (int i = 0; i < size; ++i) {
			dist[i] = INF;
			selected[i] = false;
		}
		// 자기 자신이므로 거리는 0
		dist[s] = 0;

		// 정점의 개수만큼 반복
		for (int i = 0; i < size; ++i) {
			/*	현재 점에서 최소 정점. 처음에는 항상 0을 반환한다. 
			*	처음에는 알려진 거리가 없기 때문. 
			*	두 번째 순회부터는 업데이트된 거리가 있기 때문에
			*	가장 가까운 정점이 순차적으로 구해진다.*/
			int u = getMinVertex(selected, dist);

			selected[u] = true;
			// u가 MST에 연결되어 있지 않다.
			if (dist[u] == INF) return;
			// 가장 가까운 점 하나 출력(처음에는 자기 자신)
			printf("%c ", getVertex(u));
			/*	모든 정점을 순회하면서, 현재 정점과 연결된 정점을 찾는다.
			*	만약 현재 정점과 연결된 정점 사이의 간선의 길이가 INF라면 연결되어 있지 않다는 뜻.
			*	INF가 아니라면 연결되어 있다는 뜻이다. 그 다음
			*	연결된 그 정점이 선택되어지지 않았고 현재 구한 길이가 알려진 길이보다 작다면
			*	길이를 더 짧은 길이로 업데이트 해준다. 이것을 해당 정점에 연결된 모든 정점에 대해 수행한다.
			*	또한 여기서 해당 정점을 selected 해주지 않는 것을 주목하자. */
			for (int v = 0; v < size; ++v)
				if (getEdge(u, v) != INF)
					if (!selected[v] && getEdge(u, v) < dist[v])
						dist[v] = getEdge(u, v);
		}
		printf("\n");
	}

	// 현재까지 알려진 정보에서 거리가 최소인 정점을 반환
	int getMinVertex(bool* selected, int* dist)
	{
		int minv = 0;
		int mindist = INF;
		// 모든 정점을 순회하면서
		for (int v = 0; v < size; ++v)
			/*	만약 아직 선택되어지지 않았고, v점까지의 거리가 무한(처음에는 무한이고, 이후로는 다른 정점까지의 거리임)보다 작다면
			*	그 거리를 v점까지의 최소거리라고 보고 mindist에 저장
			*	minv는 최소거리를 갖는 정점임.
			*	아래 if문은 for문을 돌면서 여러 번 진입할 수 있다.
			*	최종적으로 for문이 끝날때는 현재까지 알려진 모든 정점의 거리중 가장 가까운 정점과 거리를 구하게된다.*/
			if (!selected[v] && dist[v] < mindist) {
				mindist = dist[v];
				minv = v;
			}
		// 최종적으로 구해진 최소거리 정점
		return minv;
	}

private:
	// dist배열의 원소는 시작정점으로부터 어떤 정점까지의 최소거리
	// found배열의 원소는 시작 정점 v로부터의 최단 경로가 이미 발견된 정점들의 여부
	// 정점들이 발견되었다면 true
	int dist[MAX_VTXS];
	bool found[MAX_VTXS];

public:
	// 방문하지 않은 정점들 중에서 최단 경로 거리가 가장 작은 정점을 찾아 반환
	// 우선순위 큐로 바꾸면 더 빠르게 수행할 수 있음
	int chooseVertex()
	{
		int min = INF;
		int minpos = -1;
		// 모든 정점을 순회
		for(int i = 0; i < size; ++i)
			/*	현재까지 발견된 정점 사이의 거리 중 최솟값을 찾는다.
			*	만약 현재 알려진 정점과의 거리가 이제껏 발견된 정점과의 거리보다 작고,
			*	그 정점이 아직 집합 S에 추가되지 않았다면
			*	최솟값인 min을 업데이트 하고, 최단 경로 정점을 minpos에 저장 */
			if (dist[i] < min && !found[i]) {
				min = dist[i];
				minpos = i;
			}
		// 최종적으로 모든 정점을 순회하면서 최단 경로 거리가 가장 작은 정점을 구한다.
		return minpos;
	}

	void ShortestPath(int start)
	{
		// 초기화
		for (int i = 0; i < size; ++i) {
			dist[i] = getEdge(start, i);
			found[i] = false;
		}

		// 시작 지점은 바로 집합 S에 넣는다.
		found[start] = true;
		// 자기 자신과의 거리 0
		dist[start] = 0;

		// 모든 정점을 순회하면서
		for (int i = 0; i < size; ++i) {
			printf("Step%2d:", i + 1);
			// 시작 정점으로부터 정점 i까지의 거리 출력
			printDistance();
			// 시작 정점으로부터 직접적으로 연결된 정점들 중 최소 경로를 가진 정점을 반환
			int u = chooseVertex();
			// 그 정점 발견했고 집합 S에 추가
			found[u] = true;
			// 다시 모든 점을 순회하면서 목적은 새롭게 S에 추가된 정점 u로 인해 바뀔 최소 경로를 업데이트
			for (int w = 0; w < size; ++w) {
				// 집합 S에 포함되지 않은 정점이라면
				if (found[w] == false)
					/*	length(start, u) + length(u, w) < length(start, w)
					*	즉 시작정점에서 u를 거쳐 w로 가는 경로와, 시작정점에서 직접적으로 w로 가는 경로를 비교
					*	만약 작다면 업데이트 만약 크다면 아무것도 안한다. */
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
		// 배열 초기화
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				A[i][j] = getEdge(i, j);

		// k는 i에서 j점까지에 사용한 정점들이다. 0~k정점 사용함
		/*	그러니까 정점 i에서 정점 j로 가는 경로를 구할껀데, 처음에는 k=0 이므로, 정점 0을 
		*	거쳐갈지 직접적으로 갈지는 모두 구해서 최소 경로를 찾는다.
		*	이 과정은 그래프에 있는 모든 정점 i에서 모든 각 정점 j로 가는 경로를 찾을 때까지다. (여전히 k=0이므로 0을 거쳐가거나 아니거나)
		*	그 다음 k=1이 되면 이미 k=0일때의 정점 사이의 거리가 다 구해졌으므로(물론 여전히 연결되지 않은 정점이 있을 수 있다, 경로의 길이는 INF가 되겠지), 
		*	이것을 기반으로 정점 i에서 j로 가는데 정점 1을 거쳐갈지 아니면 직접적으로 갈지 계산해서 결정한다. 
		*	여기서 i에서 j로 가는 길이는 위 k=0일때 최소 경로로 업데이트 되었다(물론 여전히 연결 안되서 INF일수도 있다).
		*	이 과정을 반복하면 최종적으로 모든 정점에서 모든 정점까지의 최소 경로를 구할 수 있게 된다. */
		for (int k = 0; k < size; ++k){
			for (int i = 0; i < size; ++i)
				for (int j = 0; j < size; ++j)
					/*	k 까지의 정점을 사용하여 최단 경로를 구하는데
					*	만약 i 정점에서 j 정점으로 가는데 k를 거쳐서 가는 경로가 i에서 j로 직접 가는 경로보다 작다면
					*	if문을 만족한다(참이된다). 새로운 최소 경로를 찾은 것이므로 그 거리를 업데이트 한다. */
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