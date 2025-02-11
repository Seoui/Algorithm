#include "WGraph.h"
#include <limits>
#include <iostream>
int main()
{
	WGraph g;
	g.load("graph3.txt");
	printf("가중치 그래프 (graph.txt)\n");
	g.display();
	printf("======================================\n");
	WGraph g1;
	g1.load("graph3.txt");
	printf("MST\n");
	g1.Kruskal();
	printf("======================================\n");
	WGraph g2;
	g2.load("graph3.txt");
	printf("MST\n");
	g2.Prim(0);
	printf("======================================\n");
	WGraph g3;
	g3.load("graph4.txt");
	printf("Dijkstra algorithm\n");
	g3.ShortestPath(0);
	printf("======================================\n");
	WGraph g4;
	g4.load("graph4.txt");
	printf("Floyed algorithm\n");
	g4.ShortestPathFloyed();
	return 0;
}