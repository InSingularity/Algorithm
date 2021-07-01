#include "pch.h"
#include <iostream>
#include "SequentialStack.h"

void InitStack(SqStack *& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}

void DestroyStack(SqStack *& s)
{
	free(s);
	s = NULL;
}

bool StackEmpty(SqStack * s)
{
	return (s->top == -1);
}

bool Push(SqStack *& s, ElemType e)
{
	if (s->top == MaxSize - 1)
		return false;

	s->data[++s->top] = e;
	return true;
}

bool Pop(SqStack *& s, ElemType & e)
{
	if (s->top == -1)
		return false;
	
	e = s->data[s->top--];
	return true;
}

bool GetTop(SqStack * s, ElemType & e)
{
	if (s->top == -1)
		return false;

	e = s->data[s->top];
	return true;
}
