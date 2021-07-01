#include "pch.h"
#include <iostream>
#include "LinkList.h"

void CreateListF(LinkList *& L, ElemType a[], int n)
{
	LinkList* s;
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;//建立头节点

	for (int i = 0; i < n; i++)
	{
		s = (LinkList*)malloc(sizeof(LinkList));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

void CreateListR(LinkList *& L, ElemType a[], int n)
{
	LinkList* s,* r;
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;
	r = L;

	for (int i = 0; i < n; i++)
	{
		s = (LinkList*)malloc(sizeof(LinkList));
		s->data = a[i];
		s->next = NULL;
		r->next = s;
		r = s;
	}
}

void InitList(LinkList *& L)
{
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL; // 创建头节点
}

void DestroyList(LinkList *& L)
{
	LinkList* pre = L, *p = L->next;

	while (NULL != p)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}

bool ListEmpty(LinkList * L)
{
	return (NULL == L->next);
}

int ListLength(LinkList * L)
{
	LinkList* p = L;
	int n = 0;

	while (NULL != p->next)
	{
		n++;
		p = p->next;
	}
	return n;
}

void DispList(LinkList * L)
{
	LinkList* p = L->next;

	while (NULL != p)
	{
		std::cout << p->data;
		p = p->next;
	}
	std::cout << std::endl;
}

bool GetElem(LinkList * L, int i, ElemType & e)
{
	if (i <= 0)
		return false;

	LinkList* p = L;
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

int LocateElem(LinkList * L, ElemType e)
{
	LinkList* p = L;
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

bool ListInsert(LinkList *& L, int i, ElemType e)
{
	LinkList* p = L, *s;
	int j = 0;
	
	if (i <= 0)
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
		s = (LinkList*)malloc(sizeof(LinkList));
		s->data = e;
		s->next = p->next;
		p->next = s;
	}
	return true;
}

bool ListDelete(LinkList *& L, int i, ElemType & e)
{
	LinkList * pre = L, * p;
	int j = 0;

	if (i <= 0)
		return false;

	while (j < i - 1 && NULL != pre)
	{
		j++;
		pre = pre->next;
	}

	if (NULL == pre)
		return false;
	else
	{
		p = pre->next;
		if (NULL == p)
			return false;
		pre->next = p->next;
		e = p->data;
		free(p);
	}
	return true;
}
