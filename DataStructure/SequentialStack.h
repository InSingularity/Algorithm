#pragma once

#ifndef MaxSize
#define MaxSize 50
#endif // !MaxSize

typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top; // �����е�ջ��Ϊ��s->top = -1
}SqStack;

void InitStack(SqStack *& s);
void DestroyStack(SqStack *& s);
bool StackEmpty(SqStack * s);
bool Push(SqStack *& s, ElemType e);
bool Pop(SqStack *& s, ElemType & e);
bool GetTop(SqStack * s, ElemType & e);
