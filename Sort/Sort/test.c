#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"



void TestInsertSort()
{
	int a[] = { 3, 5, 3, 2, 1, 4, 7, 8, 9, 6, 5 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestShellSort()
{
	int a[] = { 3, 23, 34, 6, 87, 9, 8, 73, 62, 5, 43, 3, 2, 1, 0 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	ShellSort(a, sizeof(a) / sizeof(a[0]));
}

void TestSelectSort()
{
	int a[] = { 3,23,53,64,23,75,85,3,75,23,75,43,34,23,0,-3,-23,43 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestHeapSort()
{
	int a[] = { 2,4,3,23,54,233,-32,-54,-6,0,-3,54,23,345,32,43,-34 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestBubbleSort()
{
	int a[] = { 23,53,23,54,-34,3,-324,-54,-23,54,0,3,-43,23,34,-544 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}

void TestQuickSort()
{
	int a[] = { 3, 1, 4 ,1, 7, 9, 8, 2, 0, 5 };
	PrintArray(a, sizeof(a) / sizeof(0));
	QuickSort(a, 0, sizeof(a) / sizeof(0) - 1);
	PrintArray(a, sizeof(a) / sizeof(0));
}

void TestMergeSort()
{
	int a[] = { 10,6,7,1,3,9,7,5};
	PrintArray(a, sizeof(a) / sizeof(0));
	MergeSortNonR(a, sizeof(a) / sizeof(0));
	PrintArray(a, sizeof(a) / sizeof(0));
}

//≈≈–Ú–‘ƒ‹≤‚ ‘
void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	BubbleSort(a5, N);
	int end5 = clock();

	int begin6 = clock();
	QuickSort(a6, 0, N-1);
	int end6 = clock();

	int begin7 = clock();
	MergeSort(a7, N);
	int end7 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("BubbleSort:%d\n", end5 - begin5);
	printf("QuickSort:%d\n", end6 - begin6);
	printf("MergeSort:%d\n", end7 - begin7);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}


int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestHeapSort();
	//TestBubbleSort();
	//TestQuickSort();
	//TestMergeSort();
	TestOP();
	return 0;
}
