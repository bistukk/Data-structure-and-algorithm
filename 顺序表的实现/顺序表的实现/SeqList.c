#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
}

void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDateType* tmp = (SLDateType*)realloc(ps->a, newcapacity * sizeof(SLDateType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}


void SeqListPushBack(SL* ps, SLDateType x)
{
	//如果没有空间就扩容
	/*SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;*/
	SeqListInsert(ps, ps->size, x);
}

void SeqListPopBack(SL* ps)
{
	//检查是否删除越界
	/*assert(ps->size > 0);
	ps->size--;*/
	SeqListErase(ps, ps->size-1);
}

void SeqListPushFront(SL* ps, SLDateType x)
{
	//判断是否需要增容
	/*SeqListCheckCapacity(ps);

	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;*/
	SeqListInsert(ps, 0, x);
}

void SeqListPopFront(SL* ps)
{
	/*assert(ps->size > 0);
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}
	ps->size--;*/
	SeqListErase(ps, 0);
}

int SeqListFind(SL* ps, SLDateType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SL* ps, int pos, SLDateType x)
{
	assert(pos <= ps->size || pos >= 0);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	//挪动数据
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SL* ps, int pos)
{
	assert(pos < ps->size || pos >= 0);
	SeqListCheckCapacity(ps);
	int begin = pos+1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}
	ps->size--;
}