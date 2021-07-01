#include "pch.h"
#include <iostream>
#include "LinkQueue.h"

void InitQueue(LinkQueue *& q)
{
	q = (LinkQueue*)malloc(sizeof(LinkQueue));
	q->front = q->rear = NULL;
}

void DestroyQueue(LinkQueue *& q)
{
	DataNode * pre = q->front,
		     * p;
	if (NULL != pre)
	{
		p = pre->next;
		while (NULL != p)
		{
			free(pre);
			pre = p;
			p = p->next;
		}
		free(pre); //释放最后一个数据节点
	}
	free(q); //释放链队节点
}

bool QueueEmpty(LinkQueue * q)
{
	return (q->rear == NULL);
}

void EnQueue(LinkQueue *& q, ElemType e) //类似队列尾插法
{
	DataNode * p = (DataNode*)malloc(sizeof(DataNode));
	p->data = e;
	p->next = NULL;
	if (NULL == q->rear)
	{
		q->front = q->rear = p;
	}
	else
	{
		q->rear->next = p;
		q->rear = p;
	}
}

bool DeQueue(LinkQueue *& q, ElemType & e)
{
	DataNode *p;
	if (NULL == q->rear)
		return false;
	p = q->front;
	if (q->front == q->rear) //队列只有一个数据节点
		q->front = q->rear = NULL;
	else
		q->front = p->next; //队列两个及以上个数据节点
	e = p->data;
	free(p);
	return true;
}
