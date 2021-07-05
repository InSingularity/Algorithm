//顺序串：参数采用直接传递顺序串的方法，不同于顺序表指针
#pragma once
#ifndef MaxSize
#define MaxSize 50
#endif // !MaxSize

typedef struct
{
	char data[MaxSize];
	int length;
}SqString;

void StrAssign(SqString & s, char sctr[]);
void DestroyStr(SqString & s);
void StrCopy(SqString & s, SqString t);
bool StrEqual(SqString s, SqString t);
int StrLength(SqString s);
SqString Concat(SqString s, SqString t);
SqString SubStr(SqString s, int i, int j);
SqString InsStr(SqString s1, int i, SqString s2);
SqString DelStr(SqString s, int i, int j);
SqString RepStr(SqString s, int i, int j, SqString t);
void DispStr(SqString s);