#include "pch.h"
#include <iostream>
#include "ThreadBTree.h"

TBTree * pre; //�շ��ʹ��Ľڵ�
void Thread(TBTree *& p)
{
	if (NULL != p)
	{
		Thread(p->lchild); //������������

		if (NULL == p->lchild) //���Ӳ����ڣ�����ǰ��������
		{
			p->lchild = pre;
			p->ltag = 1;
		}
		else
			p->ltag = 0;
		
		if (NULL == pre->rchild) //��pre�ĺ����ڵ�������
		{
			pre->rchild = p;
			pre->rtag = 1;
		}
		else
			pre->rtag = 0;

		pre = p;
		Thread(p->rchild); //������������
	}
}

TBTree * CreateThread(TBTree * b)
{
	TBTree * root;
	root = (TBTree*)malloc(sizeof(TBTree));
	root->ltag = 0;
	root->rtag = 1;
	root->rchild = b;

	if (NULL == b) //�ն�����
		root->lchild = root;
	else
	{
		root->lchild = b;
		pre = root; // pre�ǽ��p��ǰ����㣬����������
		Thread(b);
		pre->rchild = root; //����ָ��ͷ��������
		pre->rtag = 1;
		root->rchild = pre; //ͷ�����������
	}

	return root;
}

void ThInOrder(TBTree * tb)
{
	TBTree * p = tb->lchild;
	while (p != tb)
	{
		while (0 == p->ltag) //�ҿ�ʼ���
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
