#pragma once
#define MAXV 5 //最大的顶点个数
#define INF 32767 //定义无穷大

//邻接矩阵存储
typedef char* InfoType;
typedef struct
{
	int no;				//顶点的编号
	InfoType info;		//顶点的其它信息
}VertexType;			//顶点的类型信息

typedef struct
{
	int edges[MAXV][MAXV];  //邻接矩阵数组
	int n;					//顶点数
	int e;					//边数
	VertexType vexs[MAXV];  //存放顶点信息
}MatGraph;					//完整的图邻接矩阵类型

//邻接表存储
typedef struct ANode
{
	int adjvex;				//该边的邻接点编号
	struct ANode * nextarc; //指向下一条边的指针
	int weight;				//该边的相关信息，如权值
}ArcNode;					//边结点的类型

typedef struct Vnode
{
	InfoType info;			//顶点的其它信息
	ArcNode * firstarc;		//指向第一个边结点
}VNode;						//邻接表的头结点类型

typedef struct
{
	VNode adjlist[MAXV];	//邻接表的头结点数组
	int n;					//图中的顶点数
	int e;					//边数
}AdjGraph;					//完整的图邻接表类型

typedef struct
{
	int u;					//边的起始顶点
	int v;					//边的终止顶点
	int w;					//边的权值
}Edge;							//用于克鲁斯卡尔算法


//用邻接矩阵数组创建邻接表
void CreateAdj(AdjGraph *& G, int A[MAXV][MAXV], int n, int e);
void DispAdj(AdjGraph * G);
void DestroyAdj(AdjGraph *& G);

//邻接表与邻接矩阵的相互转换
void MatToList(MatGraph g, AdjGraph *& G);
void ListToMat(AdjGraph * G, MatGraph & g);

//图遍历（所有点均访问）
void DFS(AdjGraph * G, int v);
void BFS(AdjGraph * G, int v);

//生成树
void Prim(MatGraph g, int v);    //普里姆算法
void Kruskal(MatGraph g);	     //克鲁斯卡尔

//最短路径
void Dijkstra(MatGraph g, int v);//狄克斯特拉算法
void Floyd(MatGraph g);			 //弗洛伊德算法