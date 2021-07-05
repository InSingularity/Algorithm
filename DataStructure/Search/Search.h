#pragma once
//顺序查找(必须有序)
int SeqSearch(int R[], int n, int key);

//折半查找
int BinSearch(int R[], int n, int key);

//分块查找
//将表R[0..n-1]均分为b块，前b-1块的个数为s=n/b(取大)
//最后一块<=s,分块有序（递增），块内无序
#define MAXI 50 //索引表最大长度
typedef struct
{
	int key;   //块内最大值
	int link;  //块的起始下标
}IdxType;      //索引表元素的类型
int IdxSearch(IdxType I[], int b, int R[], int n, int key);