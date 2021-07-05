//非循环队列
//队空：q->front == q->rear
//队满：q->rear == MaxSize-1
//rear 为队尾,front 为队头
//而且有两种方式，1：front指向队头元素，rear指向队尾的下一个元素 2：front指向队头的前一个元素，rear指向队尾元素
//下述代码为第2种，需特别注意
#pragma once
#ifndef MaxSize
#define MaxSize 50
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
#endif // 


void InitQueue1(SqQueue *& q);
void DestroyQueue1(SqQueue *& q);
bool QueueEmpty1(SqQueue * q);
bool EnQueue1(SqQueue *& q, ElemType e);
bool DeQueue1(SqQueue *& q, ElemType & e);