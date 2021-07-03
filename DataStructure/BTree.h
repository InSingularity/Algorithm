#pragma once

typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node * lchild;
	struct node * rchild;
}BTree;

//�������ű�ʾ����ʾ�Ķ������ַ���
void CreateBTree(BTree *& b, char * str);
void DestroyBTree(BTree *& b);
BTree * FindNode(BTree * b, ElemType x);
BTree * LchildNode(BTree * p);
BTree * RchildNode(BTree * p);
int BTHeight(BTree * b);
void DisBTree(BTree * b);

//�����������ĵݹ��㷨
void PreOrder(BTree * b);
void InOrder(BTree * b);
void PostOrder(BTree * b);

//�����������ķǵݹ��㷨
void PreOrder1(BTree * b);
void InOrder1(BTree * b);
void PostOrder1(BTree * b);
void LevelOrder(BTree * b);