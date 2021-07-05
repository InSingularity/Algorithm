//循环队列
//对空：q->rear == q->front
//队满：(q->rear + 1) % MaxSize == q->front
//rear 为队尾,front 为队头
//而且有两种方式，1：front指向队头元素，rear指向队尾的下一个元素 2：front指向队头的前一个元素，rear指向队尾元素
//下述代码为第2种,需特别注意
#pragma once
#ifndef MaxSize
#define MaxSize 5
#endif // !MaxSize

typedef char ElemType;

#ifndef SqQueue_button
#define SqQueue_button
typedef struct
{
	ElemType data[MaxSize];
	int front,
		rear;
}SqQueue;
#endif // !SqQueue_button

void InitQueue(SqQueue *& q);
void DestroyQueue(SqQueue *& q);
bool QueueEmpty(SqQueue * q);
bool EnQueue(SqQueue *& q, ElemType e);
bool DeQueue(SqQueue *& q, ElemType & e);