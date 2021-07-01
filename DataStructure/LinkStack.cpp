#include "pch.h"
#include <iostream>
#include "LinkStack.h"

void InitStack(LinkStack *& s)
{
	s = (LinkStack*)malloc(sizeof(LinkStack));
	s->next = NULL;
}

void DestroyStack(LinkStack *& s)
{
	LinkStack * pre = s, 
			  * p = s->next;
	
	while (NULL != p)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}

bool StackEmpty(LinkStack * s)
{
	return (NULL == s->next);
}

void Push(LinkStack *& s, ElemType e) //采用头插法就可以形成后进先出
{
	LinkStack * p = (LinkStack*)malloc(sizeof(LinkStack));
	p->next = s->next;
	p->data = e;
	s->next = p;
}

bool Pop(LinkStack *& s, ElemType & e)
{
	LinkStack * p = s->next;

	if (NULL == p)
		return false;

	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}

bool GetTop(LinkStack * s, ElemType & e)
{
	LinkStack * p = s->next;

	if (NULL == p)
		return false;

	e = p->data;
	return true;
}
