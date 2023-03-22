#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//leetcode 剑指Offer40.最小的K个数
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
//    //如果K=0，则返回空数组
//    if (k == 0)
//    {
//        return NULL;
//    }
//    int* retArr = (int*)malloc(sizeof(int) * k);
//    int i = 0;
//    //建K的数的大堆，先前K个拷入retArr
//    for (i = 0; i < k; i++)
//    {
//        retArr[i] = arr[i];
//    }
//    //建堆，向下调整法建大堆
//    for (i = (k - 1 - 1) / 2; i >= 0; i--)
//    {
//        adjustDown(retArr, k, i);
//    }
//    //将原数组中剩下的数和堆顶比较，如果小于堆顶数，则进堆
//    for (i = k; i < arrSize; i++)
//    {
//        if (arr[i] < retArr[0])
//        {
//            retArr[0] = arr[i];
//            adjustDown(retArr, k, 0);//进堆后向下调整一次，保持大堆
//        }
//    }
//    return retArr;
//}