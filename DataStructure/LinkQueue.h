#pragma once
//�ӿգ�q->rear == NULL(��q->front == NULL)
//������������
typedef char ElemType;

typedef struct qnode
{
	ElemType data;
	struct qnode * next;
}DataNode;

typedef struct
{
	DataNode * front;
	DataNode * rear;
}LinkQueue;

void InitQueue(LinkQueue *& q);
void DestroyQueue(LinkQueue *& q);
bool QueueEmpty(LinkQueue * q);
void EnQueue(LinkQueue *& q, ElemType e);
bool DeQueue(LinkQueue *& q, ElemType & e);
