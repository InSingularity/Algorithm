#include "pch.h"
#include <iostream>
#include "CircularQueue.h"

void InitQueue(SqQueue *& q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}

void DestroyQueue(SqQueue *& q)
{
	free(q);
}

bool QueueEmpty(SqQueue * q)
{
	return (q->front == q->rear);
}

bool EnQueue(SqQueue *& q, ElemType e)
{
	if ((q->rear + 1) % MaxSize == q->front)
		return false;

	q->rear = (q->rear + 1) % MaxSize;
	q->data[q->rear] = e;
	return true;
}

bool DeQueue(SqQueue *& q, ElemType & e)
{
	if (q->front == q->rear)
		return false;

	q->front = (q->front + 1) % MaxSize;
	e = q->data[q->front];
	return true;
}