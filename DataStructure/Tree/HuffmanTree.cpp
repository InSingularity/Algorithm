#include "pch.h"
#include "HuffmanTree.h"

void CreateHT(HTree ht[], int n0)
{
	int i, k, lnode, rnode;
	double min1, min2;

	for (i = 0; i < 2 * n0 - 1;i++)
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;

	for (i = n0;i < 2 * n0 - 1;i++) //构造哈夫曼树的n0-1个分支结点
	{
		min1 = min2 = 32767;
		lnode = rnode = -1;    //lnode、rnode为最小权重的两个结点位置
		for (k = 0; k <= i - 1; k++)
		{
			if (-1 == ht[k].parent)
			{
				if (ht[k].weight < min1)
				{
					min2 = min1;
					rnode = lnode;
					min1 = ht[k].weight;
					lnode = k;
				}
				else if (ht[k].parent < min2)
				{
					min2 = ht[k].weight;
					rnode = k;
				}
			}
		}
		ht[i].weight = ht[lnode].weight + ht[rnode].weight;
		ht[i].lchild = lnode;
		ht[i].rchild = rnode;
		ht[lnode].parent = i;
		ht[rnode].parent = i;
	}
}

void CreateHCode(HTree ht[], HCode hcd[], int n0)
{
	int i, f, c;
	HCode hc;
	for (i = 0; i < n0;i++)
	{
		hc.start = n0;
		c = i;
		f = ht[i].parent;
		while (-1 != f) //循环直到无双亲结点，即到达根节点
		{
			if (ht[f].lchild == c) //当前结点是双亲结点的右孩子
				hc.cd[hc.start--] = '0';
			else
				hc.cd[hc.start--] = '1';
			c = f;
			f = ht[f].parent;  //再对双亲结点进行同样的操作
		}
		hc.start++;  //start指向哈夫曼编码最开始的字符
		hcd[i] = hc;
	}
}
