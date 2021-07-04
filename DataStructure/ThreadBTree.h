#pragma once
typedef char ElemType;
typedef struct node
{
	ElemType data;
	int ltag, rtag;
	struct node * lchild;
	struct node * rchild;
}TBTree;

//��������������
void Thread(TBTree *& p);
TBTree * CreateThread(TBTree * b);

void ThInOrder(TBTree * b);