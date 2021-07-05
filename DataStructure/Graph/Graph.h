#pragma once
#define MAXV 5 //���Ķ������
#define INF 32767 //���������

//�ڽӾ���洢
typedef char* InfoType;
typedef struct
{
	int no;				//����ı��
	InfoType info;		//�����������Ϣ
}VertexType;			//�����������Ϣ

typedef struct
{
	int edges[MAXV][MAXV];  //�ڽӾ�������
	int n;					//������
	int e;					//����
	VertexType vexs[MAXV];  //��Ŷ�����Ϣ
}MatGraph;					//������ͼ�ڽӾ�������

//�ڽӱ�洢
typedef struct ANode
{
	int adjvex;				//�ñߵ��ڽӵ���
	struct ANode * nextarc; //ָ����һ���ߵ�ָ��
	int weight;				//�ñߵ������Ϣ����Ȩֵ
}ArcNode;					//�߽�������

typedef struct Vnode
{
	InfoType info;			//�����������Ϣ
	ArcNode * firstarc;		//ָ���һ���߽��
}VNode;						//�ڽӱ��ͷ�������

typedef struct
{
	VNode adjlist[MAXV];	//�ڽӱ��ͷ�������
	int n;					//ͼ�еĶ�����
	int e;					//����
}AdjGraph;					//������ͼ�ڽӱ�����

typedef struct
{
	int u;					//�ߵ���ʼ����
	int v;					//�ߵ���ֹ����
	int w;					//�ߵ�Ȩֵ
}Edge;							//���ڿ�³˹�����㷨


//���ڽӾ������鴴���ڽӱ�
void CreateAdj(AdjGraph *& G, int A[MAXV][MAXV], int n, int e);
void DispAdj(AdjGraph * G);
void DestroyAdj(AdjGraph *& G);

//�ڽӱ����ڽӾ�����໥ת��
void MatToList(MatGraph g, AdjGraph *& G);
void ListToMat(AdjGraph * G, MatGraph & g);

//ͼ���������е�����ʣ�
void DFS(AdjGraph * G, int v);
void BFS(AdjGraph * G, int v);

//������
void Prim(MatGraph g, int v);    //����ķ�㷨
void Kruskal(MatGraph g);	     //��³˹����

//���·��
void Dijkstra(MatGraph g, int v);//�ҿ�˹�����㷨
void Floyd(MatGraph g);			 //���������㷨