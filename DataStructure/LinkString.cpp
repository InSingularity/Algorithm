#include "pch.h"
#include <iostream>
#include "LinkString.h"

void StrAssign(LinkString *& s, char str[])
{
	LinkString * r, 
			   * p;
	s = (LinkString*)malloc(sizeof(LinkString));
	r = s;
	for (int i = 0; '\0' != str[i];i++)
	{
		p = (LinkString*)malloc(sizeof(LinkString));
		p->data = str[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

void DestroyStr(LinkString *& s)
{
	LinkString * pre = s,
			   * p = s->next;

	while (NULL != p)
	{
		free(pre);
		pre = p;
		p = p->next;
	}

	free(pre);
}

void StrCopy(LinkString *& s, LinkString * t)
{
	LinkString * p = t->next, * q, * r;
	s = (LinkString*)malloc(sizeof(LinkString));
	r = s;
	while (NULL != p)
	{
		q = (LinkString*)malloc(sizeof(LinkString));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;
}

bool StrEqual(LinkString * s, LinkString * t)
{
	LinkString * p = s->next,
			   * q = t->next;

	while (NULL != p && NULL != q && p->data == q->data)
	{
		p = p->next;
		q = q->next;
	}

	if (NULL != p && NULL != q)
		return true;

	return false;
}

int StrLength(LinkString * s)
{
	LinkString * p = s->next;
	int length = 0;

	while (NULL != p)
	{
		length++;
		p = p->next;
	}

	return length;
}

LinkString * Concat(LinkString * s, LinkString * t)
{
	LinkString * str, * p, * r;
	str = (LinkString*)malloc(sizeof(LinkString));
	str->next = NULL;
	r = str;
	s = s->next;

	while (NULL != s)
	{
		p = (LinkString*)malloc(sizeof(LinkString));
		p->data = s->data;
		r->next = p;
		r = p;
		s = s->next;
	}

	t = t->next;

	while (NULL != t)
	{
		p = (LinkString*)malloc(sizeof(LinkString));
		p->data = t->data;
		r->next = p;
		r = p;
		t = t->next;
	}

	r->next = NULL;
	return str;
}

LinkString * SubStr(LinkString * s, int i, int j)
{
	LinkString * str, * p = s->next, * q, * r;
	str = (LinkString*)malloc(sizeof(LinkString));
	str->next = NULL;
	r = str;

	if (i <= 0 || i > StrLength(s) || j <= 0 || i + j - 1 > StrLength(s))
		return str;

	for (int k = 1; k < i; k++) //k=1因为已经跳过头节点
		p = p->next;

	for (int k = 0; k < j; k++)
	{
		q = (LinkString*)malloc(sizeof(LinkString));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}

	r->next = NULL;
	return str;
}

LinkString * InsStr(LinkString * s, int i, LinkString * t)
{
	LinkString * str, * ps = s->next, * pt = t->next, * q, * r;
	str = (LinkString*)malloc(sizeof(LinkString));
	str->next = NULL;
	r = str;

	if (i <= 0 || i > StrLength(s) + 1)
		return str;

	while (NULL != ps && i > 1)
	{
		q = (LinkString*)malloc(sizeof(LinkString));
		q->data = ps->data;
		r->next = q;
		r = q;
		ps = ps->next;
		i--;
	}

	while (NULL != pt)
	{
		q = (LinkString*)malloc(sizeof(LinkString));
		q->data = pt->data;
		r->next = q;
		r = q;
		pt = pt->next;
	}

	while (NULL != ps)
	{
		q = (LinkString*)malloc(sizeof(LinkString));
		q->data = ps->data;
		r->next = q;
		r = q;
		ps = ps->next;
	}

	r->next = NULL;
	return str;
}

LinkString * DelStr(LinkString * s, int i, int j)
{
	LinkString * str, * r, * p = s->next, * q;
	str = (LinkString*)malloc(sizeof(LinkString));
	str->next = NULL;
	r = str;

	if (i <= 0 || i > StrLength(s) || j<0 || i + j - 1>StrLength(s))
		return str;

	for (int k = 1; k < i; k++)
	{
		q = (LinkString*)malloc(sizeof(LinkString));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}

	for (int k = 0; k < j; k++) 
		p = p->next;

	while (NULL != p)
	{
		q = (LinkString*)malloc(sizeof(LinkString));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}

	r->next = NULL;
	return str;
}

LinkString * RepStr(LinkString * s, int i, int j, LinkString * t)
{
	LinkString * str, *ps = s->next, *pt = t->next, *q, *r;
	str = (LinkString*)malloc(sizeof(LinkString));
	str->next = NULL;
	r = str;

	if (i <= 0 || i > StrLength(s) || j<0 || i + j - 1 > StrLength(s))
		return str;

	for (int k = 1; k < i; k++)
	{
		q = (LinkString*)malloc(sizeof(LinkString));
		q->data = ps->data;
		r->next = q;
		r = q;
		ps = ps->next;
	}

	for (int k = 0; k < j; k++)
		ps = ps->next;

	while (NULL != pt)
	{
		q = (LinkString*)malloc(sizeof(LinkString));
		q->data = pt->data;
		r->next = q;
		r = q;
		pt = pt->next;
	}

	while (NULL != ps)
	{
		q = (LinkString*)malloc(sizeof(LinkString));
		q->data = ps->data;
		r->next = q;
		r = q;
		ps = ps->next;
	}
	
	r->next = NULL;
	return str;
}

void DispStr(LinkString * s)
{
	LinkString * p = s->next;
	while (NULL != p)
	{
		std::cout << p->data;
		p = p->next;
	}
	std::cout << std::endl;
}
