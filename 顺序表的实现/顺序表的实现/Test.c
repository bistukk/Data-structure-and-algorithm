#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void TestSeqList1()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);
	SeqListDestroy(&sl);
}

void TestSeqList2()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);
	SeqListPushFront(&sl, 6);
	SeqListPushFront(&sl, 7);
	SeqListPushFront(&sl, 20);
	SeqListPrint(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void TestSeqList3()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPrint(&sl);
	SeqListInsert(&sl, 2, 25);
	SeqListPrint(&sl);
	int pos = SeqListFind(&sl, 3);
	if (pos != -1)
	{
		SeqListInsert(&sl, pos, 40);
	}
	SeqListPrint(&sl);
	SeqListPushFront(&sl, 6);
	SeqListPushFront(&sl, 7);
	SeqListPushFront(&sl, 20);
	SeqListPrint(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void TestSeqList4()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 7);
	SeqListPushBack(&sl, 8);
	SeqListPushBack(&sl, 9);
	SeqListPushBack(&sl, 10);

	SeqListPrint(&sl);
	SeqListErase(&sl, 1);
	SeqListErase(&sl, 3);
	SeqListPrint(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);
	int pos = SeqListFind(&sl, 6);
	if (pos != -1)
	{
		SeqListErase(&sl, pos);
	}
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

int main()
{
	//TestSeqList1();
	//TestSeqList2();
	//TestSeqList3();
	TestSeqList4();

	return 0;
}