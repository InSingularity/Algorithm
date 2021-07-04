#include "pch.h"
#include <iostream>
#include "ThreadBTree.h"

TBTree * pre; //刚访问过的节点
void Thread(TBTree *& p)
{
	if (NULL != p)
	{
		Thread(p->lchild); //左子树线索化

		if (NULL == p->lchild) //左孩子不存在，进行前驱线索化
		{
			p->lchild = pre;
			p->ltag = 1;
		}
		else
			p->ltag = 0;
		
		if (NULL == pre->rchild) //对pre的后续节点线索化
		{
			pre->rchild = p;
			pre->rtag = 1;
		}
		else
			pre->rtag = 0;

		pre = p;
		Thread(p->rchild); //右子树线索化
	}
}

TBTree * CreateThread(TBTree * b)
{
	TBTree * root;
	root = (TBTree*)malloc(sizeof(TBTree));
	root->ltag = 0;
	root->rtag = 1;
	root->rchild = b;

	if (NULL == b) //空二叉树
		root->lchild = root;
	else
	{
		root->lchild = b;
		pre = root; // pre是结点p的前驱结点，供加线索用
		Thread(b);
		pre->rchild = root; //加入指向头结点的线索
		pre->rtag = 1;
		root->rchild = pre; //头结点右线索化
	}

	return root;
}

void ThInOrder(TBTree * tb)
{
	TBTree * p = tb->lchild;
	while (p != tb)
	{
		while (0 == p->ltag) //找开始结点
			p = p->lchild;
		std::cout << p->data;

		while (1 == p->rtag && p->rchild != tb)
		{
			p = p->rchild;
			std::cout << p->data;
		}

		p = p->rchild;
	}
}
