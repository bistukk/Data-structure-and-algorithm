#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"


int main()
{
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	//HeapSort(a, sizeof(a)/sizeof(HPDataType)) ;
	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(HPDataType));
	HeapPush(&hp, 13);
	int x = HeapTop(&hp);
	HeapPop(&hp);
	HeapDestroy(&hp); 
	return 0; 
}		
