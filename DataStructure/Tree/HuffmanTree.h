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
	char cd[N]; //��ŵ�ǰ���Ĺ�������
	int start;  //��ʾcd[stre..n0]�����ǹ�������
}HCode;

void CreateHT(HTree ht[], int n0);
void CreateHCode(HTree ht[], HCode hcd[], int n0);