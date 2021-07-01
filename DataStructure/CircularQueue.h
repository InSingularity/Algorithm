//ѭ������
//�Կգ�q->rear == q->front
//������(q->rear + 1) % MaxSize == q->front
//rear Ϊ��β,front Ϊ��ͷ
//���������ַ�ʽ��1��frontָ���ͷԪ�أ�rearָ���β����һ��Ԫ�� 2��frontָ���ͷ��ǰһ��Ԫ�أ�rearָ���βԪ��
//��������Ϊ��2��,���ر�ע��
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