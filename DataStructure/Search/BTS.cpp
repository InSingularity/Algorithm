#include "pch.h"
#include <iostream>
#include "BTS.h"

bool InsertBST(BSTree *& bt, int k)
{
	if (NULL == bt)  //ԭ��Ϊ�գ��²���Ľ��Ϊ�����
	{
		bt = (BSTree*)malloc(sizeof(BSTree));
		bt->key = k;
		bt->lchild = bt->rchild = NULL;
		return true;
	}
	else if (k == bt->key) //���д�����ͬ�ؼ��ֵĽ�㣬���ؼ�
		return false;
	else if (k < bt->key)
		return InsertBST(bt->lchild, k);
	else
		return InsertBST(bt->rchild, k);

	return false;
}

BSTree * CreateBST(int A[], int n)
{
	BSTree * bt = NULL;
	int i = 0;

	while (i < n)
	{
		InsertBST(bt, A[i]);
		i++;
	}

	return bt;
}

BSTree * SearchBST(BSTree * bt, int k)
{
	if (NULL == bt || k == bt->key)
		return bt;

	if (k < bt->key)
		return SearchBST(bt->lchild, k);
	else
		return SearchBST(bt->rchild, k);

	return NULL;
}

BSTree * SearchBST(BSTree * bt, int k, BSTree * f1, BSTree *& f)
{
	if (NULL == bt)
	{
		f = NULL;
		return NULL;
	}
	else if (k == bt->key)
	{
		f = f1;
		return bt;
	}
	else if (k < bt->key)
		return SearchBST(bt->lchild, k, bt, f);
	else
		return SearchBST(bt->rchild, k, bt, f);

	return NULL;
}

bool DeleteBST(BSTree *& bt, int k)
{
	if (NULL == NULL)
		return false;
	else
	{
		if (k < bt->key)
			return DeleteBST(bt->lchild, k);
		else if (k > bt->key)
			return DeleteBST(bt->rchild, k);
		else
		{
			Delete(bt);
			return true;
		}
	}

	return false;
}

void Delete(BSTree *& p)
{
	BSTree * q;
	if (NULL == p->rchild) //���û��������������Ҷ�ӽ�㣩
	{
		q = p;
		p = p->lchild;
		free(q);
	}
	else if (NULL == p->lchild) //���û��������
	{
		q = p;
		p = p->rchild;
		free(q);
	}
	else  //�����������������
		Delete1(p, p->lchild);
}

void Delete1(BSTree * p, BSTree *& r) // rָ��������
{
	BSTree * q;

	if (NULL != r->rchild)  //�ݹ��ҽ��r�������½�㣨��r�����������ֵ��
		Delete1(p, r->rchild);
	else
	{
		p->key = r->key;   //��r��ֵ�滻p��ֵ��Ȼ��ɾ��r����
		p->data = r->data;
		q = r;
		r = r->lchild;  //r���������
		free(q);
	}

}
