#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDateType;

//动态顺序表
typedef struct SeqList
{
	SLDateType* a;
	int size;  //表示数组中存储了多少个数据
	int capacity;//数组实际存储的空间容量大小
}SL;

void SeqListInit(SL* ps);
void SeqListDestroy(SL* ps);
void SeqListPrint(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps,SLDateType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDateType x);
void SeqListPopFront(SL* ps);

//查找，找到了返回x下标位置，找不到返回-1；
int SeqListFind(SL* ps, SLDateType x);
//指定pos下标位置插入
void SeqListInsert(SL* ps, int pos, SLDateType x);
//指定pos下标位置删除
void SeqListErase(SL* ps, int pos);

