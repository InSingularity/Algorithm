#pragma once
typedef char ElemType;
typedef struct DbLinkNode
{
	ElemType data;
	struct DbLinkNode * prior;
	struct DbLinkNode * next;
}DbLinkList;

void CreateDbListF(DbLinkList *& L, ElemType a[], int n);
void CreateDbListR(DbLinkList *& L, ElemType a[], int n);
void InitDbList(DbLinkList*& L);
void DestroyDbList(DbLinkList*& L);
bool DbListEmpty(DbLinkList* L);
int DbListLength(DbLinkList* L);
void DispList(DbLinkList* L);
bool GetElem(DbLinkList* L, int i, ElemType& e);
int LocateElem(DbLinkList* L, ElemType e);
bool DbListInsert(DbLinkList*& L, int i, ElemType e);
bool DbListDelete(DbLinkList*& L, int i, ElemType& e);