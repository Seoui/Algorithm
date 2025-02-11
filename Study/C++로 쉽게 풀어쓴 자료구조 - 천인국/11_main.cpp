#include "AdjMatGraph.h"
#include "AdjListGraph.h"

int main()
{
	AdjMatGraph mg;
	for (int i = 0; i < 4; ++i)
		mg.insertVertex('A' + i);
	mg.insertEdge(0, 1);
	mg.insertEdge(0, 3);
	mg.insertEdge(1, 2);
	mg.insertEdge(1, 3);
	mg.insertEdge(2, 3);
	printf("인접 행렬로 표현한 그래프\n");
	mg.display();
	mg.store("graph.txt");
	mg.reset();
	mg.load("graph.txt");
	printf("인접 행렬로 표현한 그래프 (파일: graph.txt)\n");
	mg.display();
	printf("===============================================\n");

	AdjListGraph lg;
	for (int i = 0; i < 4; ++i)
		lg.insertVertex('A' + i);
	lg.insertEdge(0, 1);
	lg.insertEdge(0, 3);
	lg.insertEdge(1, 2);
	lg.insertEdge(1, 3);
	lg.insertEdge(2, 3);
	printf("인접 리스트로 표현한 그래프\n");
	lg.display();
	printf("===============================================\n");
	AdjMatGraph mg2;
	mg2.load("graph1.txt");
	printf("그래프(graph1.txt)\n");
	mg2.display();
	printf("DFS ==> ");
	mg2.DFS(0);
	printf("\n");
	printf("BFS ==> ");
	mg2.resetVisited();
	mg2.BFS(0);
	printf("\n===============================================\n");
	AdjListGraph lg2;
	lg2.load("graph1.txt");
	printf("그래프(graph1.txt)\n");
	lg2.display();
	printf("DFS ==> ");
	lg2.DFS(0);
	printf("\n===============================================\n");
	AdjMatGraph mg3;
	for (int i = 0; i < 5; ++i)
		mg3.insertVertex('A' + i);
	mg3.insertEdge(1, 0);
	mg3.insertEdge(2, 0);
	mg3.insertEdge(3, 4);
	printf("연결 성분 테스트 그래프\n");
	mg3.display();
	mg3.findConnectedComponent();
	printf("\n===============================================\n");
	AdjListGraph lg3;
	for (int i = 0; i < 6; ++i)
		lg3.insertVertex(i);
	lg3.insertDirEdge(0, 2);
	lg3.insertDirEdge(0, 3);
	lg3.insertDirEdge(1, 3);
	lg3.insertDirEdge(1, 4);
	lg3.insertDirEdge(2, 3);
	lg3.insertDirEdge(2, 5);
	lg3.insertDirEdge(3, 5);
	lg3.insertDirEdge(4, 5);
	printf("Topology Sort:\n");
	lg3.topoSort();
	printf("===============================================\n");
	AdjMatGraph mg4;
	mg4.load("graph2.txt");
	mg4.DFS(3);
	printf("\n");
	mg4.resetVisited();
	mg4.DFS(6);
	printf("\n");
	mg4.resetVisited();
	mg4.BFS(3);
	printf("\n");
	mg4.resetVisited();
	mg4.BFS(6);
	printf("\n");

	return 0;
}