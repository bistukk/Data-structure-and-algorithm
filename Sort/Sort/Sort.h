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

void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

void BubbleSort(int* a, int n);

void QuickSort(int* a, int n);

void MergeSort(int* a, int n);