#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>

void PrintArray(int* a, int n);

//ֱ�Ӳ�������
void InsertSort(int* a, int n);

//ϣ������(ֱ�Ӳ���������Ż�)
void ShellSort(int* a, int n);

//ѡ������
void SelectSort(int* a, int n);

//������
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

//ð������
void BubbleSort(int* a, int n);

//��������
void QuickSort(int* a, int n);

//�鲢����
void MergeSort(int* a, int n);

//��������
void CountSort(int* a, int n);



