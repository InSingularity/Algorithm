#include "pch.h"
#include <iostream>
#include "SequentialQueue.h"


void InitQueue1(SqQueue *& q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}

void DestroyQueue1(SqQueue *& q)
{
	free(q);
}

bool QueueEmpty1(SqQueue * q)
{
	return (q->front == q->rear);
}

bool EnQueue1(SqQueue *& q, ElemType e)
{
	if (q->rear == MaxSize - 1)
		return false;
	q->data[++q->rear] = e;
	return true;
}

bool DeQueue1(SqQueue *& q, ElemType & e)
{
	if (q->front == q->rear)
		return false;
	e = q->data[++q->front];
	return true;
}
