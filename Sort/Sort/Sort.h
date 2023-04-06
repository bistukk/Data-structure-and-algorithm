#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>

void PrintArray(int* a, int n);

//直接插入排序
void InsertSort(int* a, int n);

//希尔排序(直接插入排序的优化)
void ShellSort(int* a, int n);

//选择排序
void SelectSort(int* a, int n);

//堆排序
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

//冒泡排序
void BubbleSort(int* a, int n);

//快速排序
void QuickSort(int* a, int n);

//归并排序
void MergeSort(int* a, int n);

//计数排序
void CountSort(int* a, int n);



