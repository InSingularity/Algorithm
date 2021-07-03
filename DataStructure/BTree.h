#pragma once

typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node * lchild;
	struct node * rchild;
}BTree;

//采用括号表示法表示的二叉树字符串
void CreateBTree(BTree *& b, char * str);
void DestroyBTree(BTree *& b);
BTree * FindNode(BTree * b, ElemType x);
BTree * LchildNode(BTree * p);
BTree * RchildNode(BTree * p);
int BTHeight(BTree * b);
void DisBTree(BTree * b);

//二叉树遍历的递归算法
void PreOrder(BTree * b);
void InOrder(BTree * b);
void PostOrder(BTree * b);

//二叉树遍历的非递归算法
void PreOrder1(BTree * b);
void InOrder1(BTree * b);
void PostOrder1(BTree * b);
void LevelOrder(BTree * b);