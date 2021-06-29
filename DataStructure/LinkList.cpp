#include "pch.h"
#include <iostream>
#include "LinkList.h"

void CreateListF(LinkNode *& L, ElemType a[], int n)
{
	LinkNode* s;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;//建立头节点

	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

void CreateListR(LinkNode *& L, ElemType a[], int n)
{
	LinkNode* s,* r;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	r = L;

	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = NULL;
		r->next = s;
		r = s;
	}
}

void InitList(LinkNode *& L)
{
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL; // 创建头节点
}

void DestroyList(LinkNode *& L)
{
	LinkNode* pre = L, *p = L->next;

	while (NULL != p)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}

bool ListEmpty(LinkNode * L)
{
	return (NULL == L->next);
}

int ListLength(LinkNode * L)
{
	LinkNode* p = L;
	int n = 0;

	while (NULL != p->next)
	{
		n++;
		p = p->next;
	}
	return n;
}

void DispList(LinkNode * L)
{
	LinkNode* p = L->next;

	while (NULL != p)
	{
		std::cout << p->data;
		p = p->next;
	}
	std::cout << std::endl;
}

bool GetElem(LinkNode * L, int i, ElemType & e)
{
	if (i < 0)
		return false;

	LinkNode* p = L;
	int j = 0;

	while (j < i && NULL != p)
	{
		j++;
		p = p->next;
	}

	if (NULL == p)
		return false;
	else
		e = p->data;

	return true;
}

int LocateElem(LinkNode * L, ElemType e)
{
	LinkNode* p = L;
	int n = 0;

	while (NULL != p)
	{
		n++;
		p = p->next;
		if (e == p->data)
			return n;
	}
	return 0;
}

bool ListInsert(LinkNode *& L, int i, ElemType e)
{
	LinkNode* p = L, *s;
	int j = 0;
	
	if (i < 0)
		return false;

	while (j < i - 1 && NULL != p) //查找第i-1个节点
	{
		j++;
		p = p->next;
	}

	if (NULL == p)
		return false;
	else
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
	}
	return true;
}

bool ListDelete(LinkNode *& L, int i, ElemType & e)
{
	LinkNode* p = L, *q;
	int j = 0;

	if (i < 0)
		return false;

	while (j < i - 1 && NULL != p)
	{
		j++;
		p = p->next;
	}

	if (NULL == p)
		return false;
	else
	{
		q = p->next;
		if (NULL == q)
			return false;
		p->next = q->next;
		e = q->data;
		free(q);
	}
	return true;
}
