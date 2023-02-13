#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SLNode;

void SListPrint(SLNode* phead);
void SListPushBack(SLNode** pphead, SLDataType x);
void SListPopBack(SLNode** pphead);
void SListPushFront(SLNode** pphead, SLDataType x);
void SListPopFront(SLNode** pphead);
SLNode* SListFind(SLNode* phead, SLDataType x);
void SListInsert(SLNode** pphead, SLNode* pos, SLDataType x);
void SListEase(SLNode** pphead, SLNode* pos);
void SListDestroy(SLNode** pphead);
