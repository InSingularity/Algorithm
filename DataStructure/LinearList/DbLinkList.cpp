#include "pch.h"
#include <iostream>
#include "DbLinkList.h"

//头插法
void CreateDbListF(DbLinkList *& L, ElemType a[], int n)
{
	DbLinkList * s;
	L = (DbLinkList*)malloc(sizeof(DbLinkList));
	L->prior = L->next = NULL;

	for (int i = 0; i < n; i++)
	{
		s = (DbLinkList*)malloc(sizeof(DbLinkList));
		s->prior = L;
		s->next = L->next;
		s->data = a[i];
		if (NULL != L->next)
			L->next->prior = s;
		L->next = s;
	}
}

//尾插法
void CreateDbListR(DbLinkList *& L, ElemType a[], int n)
{
	DbLinkList * s, * r;
	L = (DbLinkList*)malloc(sizeof(DbLinkList));
	L->prior = L->next = NULL;
	r = L;
	
	for (int i = 0; i < n; i++)
	{
		s = (DbLinkList*)malloc(sizeof(DbLinkList));
		s->prior = r;
		s->next = NULL;
		s->data = a[i];
		r->next = s;
		r = s;
	}
}

void InitDbList(DbLinkList *& L)
{
	L = (DbLinkList*)malloc(sizeof(DbLinkList));
	L->prior = L->next = NULL;
}

void DestroyDbList(DbLinkList *& L)
{
	DbLinkList * pre = L, *p = L->next;

	while (NULL != p)
	{
		free(pre);
		pre = p;
		p = p->next;
	}

	free(pre);
}

bool DbListEmpty(DbLinkList * L)
{
	return (NULL == L->next);
}

int DbListLength(DbLinkList * L)
{
	DbLinkList * p = L->next;
	int length = 0;
	while (NULL != p)
	{
		length++;
		p = p->next;
	}
	return (length);
}

void DispList(DbLinkList * L)
{
	DbLinkList * p = L->next;
	while (NULL != p)
	{
		std::cout << p->data;
		p = p->next;
	}
	std::cout << std::endl;
}

bool GetElem(DbLinkList * L, int i, ElemType & e)
{
	if (i <= 0)
		return false;
	DbLinkList * p = L;

	while (i > 0 && NULL != p)
	{
		i--;
		p = p->next;
	}

	if (NULL == p)
		return false;
	else
		e = p->data;

	return true;
}

int LocateElem(DbLinkList * L, ElemType e)
{
	DbLinkList * p = L->next;
	int n = 0;
	while (NULL != p)
	{
		n++;
		if (e == p->data)
			return n;
		p = p->next;
	}
	return 0;
}

bool DbListInsert(DbLinkList *& L, int i, ElemType e)
{
	if (i <= 0)
		return false;

	DbLinkList * pre = L, * s;

	while (i > 1 && NULL != pre) //找到第i-个位置,注意NULL != p这个条件一定要有，否则当i超出L的实际长度时会出错
	{
		i--;
		pre = pre->next;
	}

	if (NULL == pre)
		return false;
	else
	{
		s = (DbLinkList*)malloc(sizeof(DbLinkList));
		s->data = e;
		if (NULL != pre->next)
			pre->next->prior = s;
		s->next = pre->next;
		s->prior = pre;
		pre->next = s;
	}

	return true;
}

bool DbListDelete(DbLinkList *& L, int i, ElemType & e)
{
	if (i <= 0)
		return false;

	DbLinkList * pre = L, *p;

	while (i > 1 && NULL != pre) //找到第i-个位置
	{
		i--;
		pre = pre->next;
	}

	if (NULL == pre)
		return false;
	else
	{
		p = pre->next; //第i个节点

		if (NULL == p)
			return false;

		e = p->data;
		pre->next = p->next;

		if (NULL != p->next)
			p->next->prior = pre;

		free(p);
	}
	return true;
}
