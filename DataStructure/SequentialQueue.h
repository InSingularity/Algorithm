//��ѭ������
//�ӿգ�q->front == q->rear
//������q->rear == MaxSize-1
//rear Ϊ��β,front Ϊ��ͷ
//���������ַ�ʽ��1��frontָ���ͷԪ�أ�rearָ���β����һ��Ԫ�� 2��frontָ���ͷ��ǰһ��Ԫ�أ�rearָ���βԪ��
//��������Ϊ��2�֣����ر�ע��
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