#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
//ֱ�Ӳ�������
void InsertSort(int* a, int n);

//ϣ������(ֱ�Ӳ���������Ż�)
void ShellSort(int* a, int n);

//ѡ������
void SelectSort(int* a, int n);

void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

void BubbleSort(int* a, int n);

void QuickSort(int* a, int n);