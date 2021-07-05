#pragma once
#define N 50
typedef struct
{
	char data;
	double weight;
	int parent;
	int lchild;
	int rchild;
}HTree;

typedef struct
{
	char cd[N]; //存放当前结点的哈夫曼码
	int start;  //表示cd[stre..n0]部分是哈夫曼码
}HCode;

void CreateHT(HTree ht[], int n0);
void CreateHCode(HTree ht[], HCode hcd[], int n0);