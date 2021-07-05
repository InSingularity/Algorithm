#include "pch.h"
#include <iostream>
#include <queue>
#include "Graph.h"

#define MAX 5

void CreateAdj(AdjGraph *& G, int A[MAXV][MAXV], int n, int e)
{
	int i, j;
	ArcNode * p; //边结点
	G = (AdjGraph*)malloc(sizeof(AdjGraph));

	for (i = 0; i < n; i++)		//邻接表所有头结点的指针域置初值
		G->adjlist[i].firstarc = NULL;

	for (i = 0; i < n; i++)
	{
		for (j = n - 1; j >= 0; j--)
		{
			if (0 != A[i][j] && INF != A[i][j])
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;  //头插法
				G->adjlist[i].firstarc = p;
			}
		}
	}
	G->n = n;
	G->e = e;
}

void DispAdj(AdjGraph * G)
{
	int i;
	ArcNode * p;
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		std::cout <<"   " <<i;
		while (NULL != p)
		{
			std::cout << "   " << p->adjvex << "   " << p->weight;
			p = p->nextarc;
		}
		std::cout << std::endl;
	}
}

void DestroyAdj(AdjGraph *& G)
{
	int i;
	ArcNode * pre, * p;
	for (i = 0;i < G->n;i++)
	{
		pre = G->adjlist[i].firstarc;
		if (NULL != pre)
		{
			p = pre->nextarc;
			while (NULL != p)
			{
				free(pre);
				pre = p;
				p = p->nextarc;
			}
			free(pre);
		}
	}
	free(G);
}

void MatToList(MatGraph g, AdjGraph *& G)
{
	int i, j;
	ArcNode * p; //边结点
	G = (AdjGraph*)malloc(sizeof(AdjGraph));

	for (i = 0; i < g.n; i++)		//邻接表所有头结点的指针域置初值
		G->adjlist[i].firstarc = NULL;

	for (i = 0;i < g.n;i++)
	{
		for (j = g.n - 1;j >= 0;j++)
		{
			if (0 != g.edges[i][j] && INF != g.edges[i][j])
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->weight = g.edges[i][j];
				p->nextarc = G->adjlist[i].firstarc;  //头插法
				G->adjlist[i].firstarc = p;
			}
		}
	}
	G->n = g.n;
	G->e = g.e;
}

void ListToMat(AdjGraph * G, MatGraph & g)
{
	int i;
	ArcNode * p;
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc; //扫描所有的单链表
		while (NULL != p)
		{
			g.edges[i][p->adjvex] = p->weight;
			p = p->nextarc;
		}
	}
	g.n = G->n;
	g.e = G->e;
}

int visited[MAX] = { 0 };
void DFS(AdjGraph * G, int v)
{
	ArcNode * p;
	visited[v] = 1;
	std::cout << v;
	p = G->adjlist[v].firstarc; //指向顶点v的第一个邻接点

	while (NULL != p)
	{
		if (0 == visited[p->adjvex])   //若p->adjvex顶点未被访问过，递归访问它
			DFS(G, p->adjvex);
		p = p->nextarc;
	}
}

void BFS(AdjGraph * G, int v)
{
	int w, i;
	ArcNode * p;
	std::queue<int> qu;
	int visited1[MAX];

	for (i = 0;i < G->n; i++)
		visited1[i] = 0;

	std::cout << "  " << v;
	visited1[v] = 1;
	qu.push(v);

	while (!qu.empty())
	{
		w = qu.front();
		qu.pop();
		p = G->adjlist[w].firstarc;
		
		while (NULL != p) //访问w的所有邻接点，并进队
		{
			if (0 == visited1[p->adjvex])
			{
				std::cout << "  " << p->adjvex;
				visited1[p->adjvex] = 1;
				qu.push(p->adjvex);
			}
			p = p->nextarc;
		}
	}
	std::cout << std::endl;
}

void Prim(MatGraph g, int v)
{
}

void Kruskal(MatGraph g)
{
}

void Dijkstra(MatGraph g, int v)
{
}

void Floyd(MatGraph g)
{
}
