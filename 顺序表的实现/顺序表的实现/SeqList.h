#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDateType;

//��̬˳���
typedef struct SeqList
{
	SLDateType* a;
	int size;  //��ʾ�����д洢�˶��ٸ�����
	int capacity;//����ʵ�ʴ洢�Ŀռ�������С
}SL;

void SeqListInit(SL* ps);
void SeqListDestroy(SL* ps);
void SeqListPrint(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps,SLDateType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDateType x);
void SeqListPopFront(SL* ps);

//���ң��ҵ��˷���x�±�λ�ã��Ҳ�������-1��
int SeqListFind(SL* ps, SLDateType x);
//ָ��pos�±�λ�ò���
void SeqListInsert(SL* ps, int pos, SLDateType x);
//ָ��pos�±�λ��ɾ��
void SeqListErase(SL* ps, int pos);

