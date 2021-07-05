#include "pch.h"
#include <iostream>
#include "Search.h"

int SeqSearch(int R[], int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (R[i] == key)
			return (i + 1);
	}

	return 0;
}

int BinSearch(int R[], int n, int key)
{
	int low = 0,
		high = n - 1,
		mid = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (key == R[mid])
			return mid + 1;

		if (key > R[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}

	return 0;
}

int IdxSearch(IdxType I[], int b, int R[], int n, int key)
{
	int low = 0,
		high = b - 1,
		mid,
		i,
		s = (n + b - 1) / b; //s为每块的个数

	if (key > I[b - 1].key)
		return 0;

	while (low <= high) //索引表折半查找，找到位置为high+1
	{
		mid = (low + high) / 2;
		if (I[mid].key < key)
			low = mid + 1;
		else
			high = mid - 1;
	}

	for (i = I[high + 1].link; i <= I[high + 1].link + s - 1; i++)
		if (R[i] == key)
			return i + 1;

	return 0;
}
