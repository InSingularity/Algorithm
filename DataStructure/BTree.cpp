#include "pch.h"
#include "BTree.h"
#include <iostream>
#include <stack>
#include <queue>

void CreateBTree(BTree *& b, char * str)
{
	BTree * p;
	std::stack<BTree*> st;
	int k, j = 0;
	char ch;
	b = NULL; //初始时二叉树为空
	ch = str[j];
	
	while ('\0' != ch)
	{
		switch (ch)
		{
			case '(':
			{
				st.push(p);
				k = 1;
				break;
			}
			case ')':
			{
				st.pop();
				break;
			}
			case ',':
			{
				k = 2;
				break;		
			}
			default:
			{
				p = (BTree*)malloc(sizeof(BTree));
				p->data = ch;
				p->lchild = p->rchild = NULL;
				
				if (NULL == b)
					b = p;
				else
				{
					switch (k)
					{
					case 1:
					{
						st.top()->lchild = p;
						break;
					}
					case 2:
					{
						st.top()->rchild = p;
						break;
					}
					default:
						break;
					}
				}
				break;
			}
		}
		j++;
		ch = str[j];
	}
}

void DestroyBTree(BTree *& b)
{
	if (NULL != b)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}

BTree * FindNode(BTree * b, ElemType x)
{
	BTree * p;

	if (NULL == b)
		return NULL;
	else if (b->data == x)
		return b;
	else
	{
		p = FindNode(b->lchild, x);
		if (NULL != p)
			return p;
		else
			return FindNode(b->rchild, x);
	}

	return NULL;
}

BTree * LchildNode(BTree * p)
{
	return p->lchild;
}

BTree * RchildNode(BTree * p)
{
	return p->rchild;
}

int BTHeight(BTree * b)
{
	int lchild = 0, rchild = 0;
	if (NULL == b)
		return 0;
	else
	{
		lchild = BTHeight(b->lchild);
		rchild = BTHeight(b->rchild);
		return (lchild > rchild) ? (lchild + 1) : (rchild + 1);
	}
	return 0;
}

void DisBTree(BTree * b)
{
	if (NULL != b)
	{
		std::cout << b->data;
		if (NULL != b->lchild || NULL != b->rchild)
		{
			std::cout << "(";
			DisBTree(b->lchild);
			if (NULL != b->rchild)
				std::cout << ",";
			DisBTree(b->rchild);
			std::cout << ")";
		}
	}
}


void PreOrder(BTree * b)
{
	if (NULL != b)
	{
		std::cout << b->data;
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}

void InOrder(BTree * b)
{
	if (NULL != b)
	{
		InOrder(b->lchild);
		std::cout << b->data;
		InOrder(b->rchild);
	}
}

void PostOrder(BTree * b)
{
	if (NULL != b)
	{
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		std::cout << b->data;
	}
}

void PreOrder1(BTree * b)
{
	BTree * p;
	std::stack<BTree*> st;
	p = b;
	while (!st.empty() || NULL != p)
	{
		while (NULL != p) //访问所有左下节点并进栈
		{
			std::cout << p->data;
			st.push(p);
			p = p->lchild; //一直访问左孩子
		}
		if (!st.empty()) 
		{
			p = st.top();
			st.pop();
			p = p->rchild; //转向处理右子树
		}
	}
	std::cout << std::endl;
}

void InOrder1(BTree * b)
{
	BTree * p;
	std::stack<BTree*> st;
	p = b;
	while (!st.empty() || NULL != p)
	{
		while (NULL != p) //一直扫描左下节点，但不进行未访问
		{
			st.push(p);
			p = p->lchild;
		}
		if (!st.empty()) //此时栈顶节点（尚未访问）没有左孩子或左子树已遍历过
		{
			p = st.top();
			std::cout << p->data;
			st.pop();
			p = p->rchild;
		}
	}
	std::cout << std::endl;
}

void PostOrder1(BTree * b)
{
	BTree * p, * r;
	bool flag = false;
	std::stack<BTree*> st;
	p = b;

	do
	{
		while (NULL != p) //一直扫描左下节点，但不进行未访问
		{
			st.push(p);
			p = p->lchild;
		}

		r = NULL;    //r指向刚刚访问过的节点
		flag = true; //flag为真表示正在处理栈顶节点

		while (!st.empty() && flag)
		{
			p = st.top();
			if (p->rchild == r) //若节点p的右孩子为空或为刚刚访问过的节点
			{
				std::cout << p->data;
				st.pop();
				r = p;
			}
			else
			{
				p = p->rchild; //转向处理右子树
				flag = false;
			}
		}
	} while (!st.empty());

	std::cout << std::endl;
}

void LevelOrder(BTree * b)
{
	BTree * p;
	std::queue<BTree*> qu;
	qu.push(b);
	while (!qu.empty())
	{
		p =qu.front();
		qu.pop();
		std::cout << p->data;
		if (NULL != p->lchild)
			qu.push(p->lchild);
		if (NULL != p->rchild)
			qu.push(p->rchild);
	}
}

