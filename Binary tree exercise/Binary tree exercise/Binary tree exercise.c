#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//leetcode ��ָOffer40.��С��K����
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//void adjustDown(int* arr, int n, int root)
//{
//    int parent = root;
//    int child = 2 * parent + 1;
//
//    while (child < n)
//    {
//        if (child + 1 < n && arr[child] < arr[child + 1])
//        {
//            child++;
//        }
//        if (arr[parent] < arr[child])
//        {
//            int tmp = arr[parent];
//            arr[parent] = arr[child];
//            arr[child] = tmp;
//            parent = child;
//            child = parent * 2 + 1;
//        }
//        else
//        {
//            break;
//        }
//    }
//}
//
//int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize) {
//    *returnSize = k;
//    //���K=0���򷵻ؿ�����
//    if (k == 0)
//    {
//        return NULL;
//    }
//    int* retArr = (int*)malloc(sizeof(int) * k);
//    int i = 0;
//    //��K�����Ĵ�ѣ���ǰK������retArr
//    for (i = 0; i < k; i++)
//    {
//        retArr[i] = arr[i];
//    }
//    //���ѣ����µ����������
//    for (i = (k - 1 - 1) / 2; i >= 0; i--)
//    {
//        adjustDown(retArr, k, i);
//    }
//    //��ԭ������ʣ�µ����ͶѶ��Ƚϣ����С�ڶѶ����������
//    for (i = k; i < arrSize; i++)
//    {
//        if (arr[i] < retArr[0])
//        {
//            retArr[0] = arr[i];
//            adjustDown(retArr, k, 0);//���Ѻ����µ���һ�Σ����ִ��
//        }
//    }
//    return retArr;
//}