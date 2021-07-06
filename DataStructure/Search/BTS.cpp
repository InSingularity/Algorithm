#include "pch.h"
#include <iostream>
#include "BTS.h"

bool InsertBST(BSTree *& bt, int k)
{
	if (NULL == bt)  //原树为空，新插入的结点为根结点
	{
		bt = (BSTree*)malloc(sizeof(BSTree));
		bt->key = k;
		bt->lchild = bt->rchild = NULL;
		return true;
	}
	else if (k == bt->key) //树中存在相同关键字的结点，返回假
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
	if (NULL == p->rchild) //结点没有左子树（包含叶子结点）
	{
		q = p;
		p = p->lchild;
		free(q);
	}
	else if (NULL == p->lchild) //结点没有右子树
	{
		q = p;
		p = p->rchild;
		free(q);
	}
	else  //结点左右子树均存在
		Delete1(p, p->lchild);
}

void Delete1(BSTree * p, BSTree *& r) // r指向其左孩子
{
	BSTree * q;

	if (NULL != r->rchild)  //递归找结点r的最右下结点（即r的右子树最大值）
		Delete1(p, r->rchild);
	else
	{
		p->key = r->key;   //将r的值替换p的值，然后删除r即可
		p->data = r->data;
		q = r;
		r = r->lchild;  //r用左孩子替代
		free(q);
	}

}
