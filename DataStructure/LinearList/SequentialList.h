#pragma once
#define MaxSize 50
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;

void CreateList(SqList* &L, ElemType a[], int n);
void InitList(SqList* &L);
void DestroyList(SqList* &L);
bool ListEmpty(SqList* L);
int ListLength(SqList* L);
void DispList(SqList* L);
bool GetElem(SqList* L, int i, ElemType &e);
int LocateElem(SqList* L, ElemType e);
bool ListInsert(SqList* &L, int i, ElemType e);
bool ListDelete(SqList* &L, int i, ElemType &e);
