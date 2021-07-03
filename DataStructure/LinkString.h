#pragma once

typedef struct snode
{
	char data;
	struct snode * next;
}LinkString;

void StrAssign(LinkString *& s, char str[]);
void DestroyStr(LinkString *& s);
void StrCopy(LinkString *& s, LinkString * t);
bool StrEqual(LinkString * s, LinkString * t);
int StrLength(LinkString * s);
LinkString * Concat(LinkString * s, LinkString * t);
LinkString * SubStr(LinkString * s, int i, int j);
LinkString * InsStr(LinkString * s, int i, LinkString * t);
LinkString * DelStr(LinkString * s, int i, int j);
LinkString * RepStr(LinkString * s, int i, int j, LinkString * t);
void DispStr(LinkString * s);