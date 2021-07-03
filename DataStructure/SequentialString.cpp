#include "pch.h"
#include <iostream>
#include "SequentialString.h"

void StrAssign(SqString & s, char cstr[])
{
	int i;
	for (i = 0;  '\0' != cstr[i]; i++)
		s.data[i] = cstr[i];
	s.length = i;
}

void DestroyStr(SqString & s)
{
	//直接采用顺序串本身表示，而不是顺序指针
}

void StrCopy(SqString & s, SqString t)
{
	for (int i = 0; i < t.length; i++)
		s.data[i] = t.data[i];
	s.length = t.length;
}

bool StrEqual(SqString s, SqString t)
{
	if (s.length != t.length)
		return false;
	else
	{
		for (int i = 0; i < s.length; i++)
		{
			if (s.data[i] != t.data[i])
				return false;
		}
	}
	return true;
}

int StrLength(SqString s)
{
	return (s.length);
}

SqString Concat(SqString s, SqString t)
{
	SqString str;
	str.length = s.length + t.length;
	for (int i = 0; i < s.length; i++)
		str.data[i] = s.data[i];
	for (int i = 0;i < t.length;i++)
		str.data[s.length + i] = t.data[i];
	return str;
}

SqString SubStr(SqString s, int i, int j)
{
	SqString str;
	str.length = 0;

	if (i <= 0 || i > s.length || j<0 || i + j - 1>s.length)
		return str;

	for (int k = 0; k < j;k++)
		str.data[k] = s.data[i + k];

	str.length = j;
	return str;
}

//s2插入s1的第i(1<=i<=n+1)个位置上，不正确时返回一个空串
SqString InsStr(SqString s1, int i, SqString s2)
{
	SqString str;
	str.length = 0;
	if (i <= 0 || i > s1.length + 1)
		return str;
	for (int j = 0; j < i - 1; j++)
		str.data[j] = s1.data[j];
	for (int j = 0; j < s2.length;j++)
		str.data[i - 1 + j] = s2.data[j];
	for (int j = i - 1; j < s1.length;j++)
		str.data[j + s2.length] = s1.data[j];
	str.length = s1.length + s2.length;
	return str;
}

SqString DelStr(SqString s, int i, int j)
{
	SqString str;
	str.length = 0;
	if (i <= 0 || j <= 0 || i > s.length || i + j > s.length + 1)
		return str;
	for (int k = 0; k < i-1; k++)
		str.data[k] = s.data[k];
	for (int k = i + j - 1; k < s.length; k++)
		str.data[k - j] = s.data[k];
	str.length = s.length - j;
	return str;
}

//将串s中第i(1<=i<=n)个字符开始的连续j个字符构成的子串用t替换
SqString RepStr(SqString s, int i, int j, SqString t)
{
	SqString str;
	str.length = 0;
	if (i <= 0 || i > s.length || i + j - 1 > s.length)
		return str;
	for (int k = 0; k < i;k++)
		str.data[k] = s.data[k];
	for (int k = 0; k < t.length; k++)
		str.data[i + k - 1] = t.data[k];
	for (int k = i + j - 1;k < s.length;k++)
		str.data[t.length + k - j] = s.data[k];
	str.length = s.length - j + t.length;
	return str;
}

void DispStr(SqString s)
{
	if (s.data > 0)
	{
		for (int i = 0;i < s.length;i++)
			std::cout << s.data[i];
		std::cout << std::endl;
	}
}
