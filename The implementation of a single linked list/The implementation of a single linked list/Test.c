#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void TestSList()
{
	SLNode* plist = NULL;
	//Œ≤≤Â
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);

	SListPrint(plist);
	//Œ≤…æ
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);

	SListPrint(plist);
	//Õ∑≤Â
	SListPushFront(&plist, 6);
	SListPushFront(&plist, 7);
	SListPushFront(&plist, 8);

	SListPrint(plist);
	//Õ∑…æ
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);

	SListPrint(plist);
	//≤È’“°¢≤Â»Î
	SLNode* pos1 = SListFind(plist, 3);
	if (pos1)
	{
		SListInsert(&plist, pos1, 25);
	}
	SListPrint(plist);
	SLNode* pos2 = SListFind(plist, 1);
	if (pos2)
	{
		SListInsert(&plist, pos2, 20);
	}
	SListPrint(plist);

	//≤È’“°¢…æ≥˝
	SLNode* pos3 = SListFind(plist, 1);
	if (pos3)
	{
		SListEase(&plist, pos3);
	}
	SListPrint(plist);

	SListDestroy(&plist);
}

int main()
{
	TestSList();
	return 0;
}