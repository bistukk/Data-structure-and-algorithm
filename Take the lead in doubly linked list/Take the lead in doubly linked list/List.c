#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

LTNode* ListInit()
{
	//哨兵位的头结点
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	if (phead == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

LTNode* BuyListNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur!= phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	/*LTNode* tail = phead->prev;
	LTNode* newnode = BuyListNode(x);
	newnode->data = x;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;*/
	ListInsert(phead, x);
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	/*LTNode* tail = phead->prev;
	tail->prev->next = phead;
	phead->prev = tail->prev;
	free(tail);*/
	ListErase(phead->prev);
}

void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	/*LTNode*newnode= BuyListNode(x);
	LTNode* next = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = next;
	next->prev = newnode;*/
	ListInsert(phead->next, x);
}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	/*LTNode* prev = phead->next;
	phead->next->next->prev = phead;
	phead->next = phead->next->next;
	free(prev);*/
	ListErase(phead->next);
}

LTNode* ListFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur!=phead)
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

void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = BuyListNode(x);
	LTNode* posPrev = pos->prev;
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* posPrev = pos->prev;
	posPrev->next = pos->next;
	pos->next->prev = posPrev;
	free(pos);
	pos = NULL;
}

void ListDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}