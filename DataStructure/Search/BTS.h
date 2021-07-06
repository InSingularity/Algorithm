#pragma once
typedef char* InfoType;
typedef struct node
{
	int key;
	InfoType data;
	struct node * lchild,
				*rchild;
}BSTree;

bool InsertBST(BSTree *& bt, int k);
BSTree * CreateBST(int A[], int n);
BSTree * SearchBST(BSTree * bt, int k);
BSTree * SearchBST(BSTree * bt, int k, BSTree * f1, BSTree *& f);
bool deleteK(BSTree *& bt, int k);