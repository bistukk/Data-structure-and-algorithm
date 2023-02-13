#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

SLNode* BuyListNode(SLDataType x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListPrint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPushBack(SLNode** pphead, SLDataType x)
{
	assert(pphead);
	SLNode* newnode = BuyListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//ÕÒµ½Î²½Úµã
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPopBack(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	if ((*pphead)->next==NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLNode* tail = *pphead;
		SLNode* prev = *pphead;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

void SListPushFront(SLNode** pphead, SLDataType x)
{
	assert(pphead);
	SLNode* newnode = BuyListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopFront(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SLNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLNode* SListFind(SLNode* phead, SLDataType x)
{
	SLNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void SListInsertAfter(SLNode* pos,SLDataType x)
{
	assert(pos);
	SLNode* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListInsert(SLNode** pphead, SLNode* pos, SLDataType x)
{
	assert(pphead);
	SLNode* newnode = BuyListNode(x);
	if (*pphead == pos)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		SLNode* posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}
		posPrev->next = newnode;
		newnode->next = pos;
	}
}

void SListEaseAfter(SLNode* pos)
{
	assert(pos);
	assert(pos->next);
	SLNode* next = pos->next;
	pos->next = next->next;
	free(next);
	pos = NULL;
}

void SListEase(SLNode** pphead, SLNode* pos)
{
	assert(pphead);
	if (*pphead == pos)
	{
		SLNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
	else
	{
		SLNode* posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}
		posPrev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SListDestroy(SLNode** pphead)
{
	assert(pphead);
	 
	SLNode* cur = *pphead;
	while (cur)
	{
		SLNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}
