#pragma once
//˳�����(��������)
int SeqSearch(int R[], int n, int key);

//�۰����
int BinSearch(int R[], int n, int key);

//�ֿ����
//����R[0..n-1]����Ϊb�飬ǰb-1��ĸ���Ϊs=n/b(ȡ��)
//���һ��<=s,�ֿ����򣨵���������������
#define MAXI 50 //��������󳤶�
typedef struct
{
	int key;   //�������ֵ
	int link;  //�����ʼ�±�
}IdxType;      //������Ԫ�ص�����
int IdxSearch(IdxType I[], int b, int R[], int n, int key);