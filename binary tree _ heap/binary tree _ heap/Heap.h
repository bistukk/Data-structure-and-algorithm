<<<<<<< HEAD
#pragma once

typedef int HPDataType;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

void AdjustDown(HPDataType* a, int n, int root);

void HeapInit(Heap* php, HPDataType* a, int n);

void HeapDestroy(Heap* php);

void HeapPush(Heap* php, HPDataType x);

void HeapPop(Heap* php);

HPDataType HeapTop(Heap* php);

void HeapSort(int* a, int n);
=======
#pragma once

typedef int HPDataType;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

void AdjustDown(HPDataType* a, int n, int root);

void HeapInit(Heap* php, HPDataType* a, int n);

void HeapDestroy(Heap* php);

void HeapPush(Heap* php, HPDataType x);

void HeapPop(Heap* php);

HPDataType HeapTop(Heap* php);

void HeapSort(int* a, int n);
>>>>>>> e2150ea71eed8de021a110986d0c1356c04f639a
