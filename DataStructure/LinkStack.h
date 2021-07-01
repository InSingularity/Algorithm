#pragma once

typedef char ElemType;
typedef struct linknode
{
	ElemType data;
	struct linknode * next;
}LinkStack;

void InitStack(LinkStack *& s);
void DestroyStack(LinkStack *& s);
bool StackEmpty(LinkStack * s);
void Push(LinkStack *& s, ElemType e);
bool Pop(LinkStack *& s, ElemType & e);
bool GetTop(LinkStack * s, ElemType & e);