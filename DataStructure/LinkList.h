#pragma once
typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LinkList;

void CreateListF(LinkList*& L, ElemType a[], int n);
void CreateListR(LinkList*& L, ElemType a[], int n);
void InitList(LinkList*& L);
void DestroyList(LinkList*& L);
bool ListEmpty(LinkList* L);
int ListLength(LinkList* L);
void DispList(LinkList* L);
bool GetElem(LinkList* L, int i, ElemType& e);
int LocateElem(LinkList* L, ElemType e);
bool ListInsert(LinkList*& L, int i, ElemType e);
bool ListDelete(LinkList*& L, int i, ElemType& e);
