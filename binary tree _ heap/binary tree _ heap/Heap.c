<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HPDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;
	while (parent >= 0)
	{
		if(a[child]<a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDown(HPDataType* a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		//找出左右孩子中小(大)的那个
		if (child+1 < n && a[child] > a[child + 1])
		{
			++child;
		}

		//如果孩子小于（大于）父亲，则交换
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapInit(Heap* php, HPDataType* a, int n)
{
	assert(php);
	php->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (php->_a == NULL)
	{
		return;
	}
	memcpy(php->_a, a, sizeof(HPDataType) * n);
	php->_size = n;
	php->_capacity = n;

	//构建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(php->_a, php->_size, i);
	}
}

void HeapDestroy(Heap* php)
{
	assert(php);
	free(php->_a);
	php->_a = NULL;
	php->_capacity = php->_size = 0;
}

void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	if (php->_size == php->_capacity)
	{
		php->_capacity *= 2;
		HPDataType* tmp = (HPDataType*)realloc(php->_a, sizeof(HPDataType) * php->_capacity);
		if (tmp != NULL)
		{ 
			php->_a = tmp;
		}
	}
	php->_a[php->_size++] = x;
	AdjustUp(php->_a, php->_size,php->_size - 1);
}

void HeapPop(Heap* php) 
{
	assert(php);
	assert(php->_size > 0);
	Swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;
	AdjustDown(php->_a, php->_size, 0);
}

HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);
	return php->_a[0];
}

void HeapSort(int* a, int n)
{
	//1.建堆,排升序，建大堆，排降序，建小堆
	//注意：建堆的时间复杂度不是O(N * logN),而是O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
=======
#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HPDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;
	while (parent >= 0)
	{
		if(a[child]<a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDown(HPDataType* a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		//找出左右孩子中小(大)的那个
		if (child+1 < n && a[child] > a[child + 1])
		{
			++child;
		}

		//如果孩子小于（大于）父亲，则交换
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapInit(Heap* php, HPDataType* a, int n)
{
	assert(php);
	php->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (php->_a == NULL)
	{
		return;
	}
	memcpy(php->_a, a, sizeof(HPDataType) * n);
	php->_size = n;
	php->_capacity = n;

	//构建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(php->_a, php->_size, i);
	}
}

void HeapDestroy(Heap* php)
{
	assert(php);
	free(php->_a);
	php->_a = NULL;
	php->_capacity = php->_size = 0;
}

void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	if (php->_size == php->_capacity)
	{
		php->_capacity *= 2;
		HPDataType* tmp = (HPDataType*)realloc(php->_a, sizeof(HPDataType) * php->_capacity);
		if (tmp != NULL)
		{ 
			php->_a = tmp;
		}
	}
	php->_a[php->_size++] = x;
	AdjustUp(php->_a, php->_size,php->_size - 1);
}

void HeapPop(Heap* php) 
{
	assert(php);
	assert(php->_size > 0);
	Swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;
	AdjustDown(php->_a, php->_size, 0);
}

HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);
	return php->_a[0];
}

void HeapSort(int* a, int n)
{
	//1.建堆,排升序，建大堆，排降序，建小堆
	//注意：建堆的时间复杂度不是O(N * logN),而是O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
>>>>>>> e2150ea71eed8de021a110986d0c1356c04f639a
}