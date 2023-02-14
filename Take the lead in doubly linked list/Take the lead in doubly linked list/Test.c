#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void Test1()
{
	LTNode* plist = ListInit();
	ListPushBack(plist,1);
	ListPushBack(plist,2);
	ListPushBack(plist,3);
	ListPushBack(plist,4);
	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);

	ListPushFront(plist, 5);
	ListPushFront(plist, 6);
	ListPushFront(plist, 7);
	ListPushFront(plist, 8);
	ListPrint(plist);

	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);

	LTNode* pos1=ListFind(plist,5);
	if (pos1 != NULL)
	{
		ListInsert(pos1, 20);
	}
	ListPrint(plist);

	LTNode* pos2 = ListFind(plist, 5);
	if (pos2 != NULL)
	{
		ListErase(pos2);
		pos2 = NULL;
	}
	ListPrint(plist);

	ListDestroy(plist);
	plist = NULL;
}

int main()
{
	Test1();
	return 0;
}