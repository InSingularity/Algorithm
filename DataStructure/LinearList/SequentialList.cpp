#include "pch.h"
#include <iostream>
#include "SequentialList.h"

void CreateList(SqList *& L, ElemType a[], int n)
{
	int i = 0;
	L = (SqList*)malloc(sizeof(SqList));
	while (i < n)
	{
		L->data[i] = a[i];
		i++;
	}
	L->length = i;
}

void InitList(SqList *& L)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}

void DestroyList(SqList *& L)
{
	free(L);
}

bool ListEmpty(SqList * L)
{
	return (0 == L->length);
}

int ListLength(SqList * L)
{
	return (L->length);
}

void DispList(SqList * L)
{
	for (int i = 0; i < L->length; i++)
		std::cout << L->data[i];
	std::cout << std::endl;
}

//返回第i个元素 1 <= i <= n
bool GetElem(SqList * L, int i, ElemType & e)
{
	if (i < 1 || i > L->length)
		return false;
	else
		e = L->data[i - 1];
	return true;
}

//返回e所在的位置
int LocateElem(SqList * L, ElemType e)
{
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] == e)
			return (i + 1);
	}
	return 0;
}

//在第i（1 <= i <= n+1）个位置插入新元素
bool ListInsert(SqList *& L, int i, ElemType e)
{
	if (i<1 || i>L->length + 1)
		return false;
	i--;//物理位置
	for (int j = L->length - 1; j >= i; j--) //i之后包括i位置的元素往后移一个
		L->data[j + 1] = L->data[j];
	L->data[i] = e;
	L->length++;
	return true;
}


bool ListDelete(SqList *& L, int i, ElemType & e)
{
	if (i<1 || i>L->length)
		return false;
	i--;//物理位置
	e = L->data[i];
	while (i < L->length - 1)//i之后包括i位置的元素往前移一个
	{
		L->data[i] = L->data[i + 1];
		i++;
	}
	L->length--;
	return true;
}


