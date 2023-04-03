#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//��������(ʱ�临�Ӷ�Ϊ��O(N~2))
//插入排序(时间复杂度为：O(N~2))
void InsertSort(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n - 1; i++)//注意边界是n-1,因为是从0 �?n-2插入
	{
		//把end + 1插入[0 - end]的有序区�?
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//希尔排序(时间复杂度为：O(N~1.3 - N~2))
void ShellSort(int* a, int n)
{
	assert(a);

	int gap = n;
	while (gap > 1)
	{
		//gap > 1时让数组接近有序
		//gap == 1时相当于一躺直接插入排序，保证有序
		gap = gap / 3 + 1;// +1保证了最后一次一定是1
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
		//PrintArray(a, n);
	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//选择排序(时间复杂度是O(N~2))
void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mini, maxi;
		mini = maxi = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		
		//如果出现重叠的情�? 则需把maxi的位置修正，防止又换回来
		if (maxi == begin)
		{
			maxi = mini;
		} 
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

//堆排�?
//向下调整�?
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
} 
//时间复杂度O(log(N))
void HeapSort(int* a, int n)
{
	//排升序，建大�?
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
}

//冒泡排序(时间复杂度为:O(N~2)
void BubbleSort(int* a, int n)
{
	int end = n;
	int exchange = 0;
	while (end > 0)
	{
		for (int i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}

		//优化: 如果一躺冒泡排序没有发生交换，则说明已经有�?
		if (exchange == 0)
		{
			break;
		}
		--end;
	}
}


//����ȡ�У��������������ٳ���
int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
}

//����ָ�뷨
int PartSort1(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);
	int keyIndex = end;
	while (begin < end)
	{
		//begin�Ҵ�
		while (begin < end && a[begin] <= a[keyIndex])
		{
			++begin;
		}

		//end��С
		while (begin < end && a[end] >= a[keyIndex])
		{
			--end;
		}

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyIndex]);

	return begin;
}

//�ڿӷ�
int PartSort2(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);
	int key = a[end];
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}

		//����ҵ���key�����ұߵĿӣ�beginλ�þ��γ��µĿ�
		a[end] = a[begin];

		while (begin < end && a[end] >= key)
		{
			--end;
		}

		//�ұ��ҵ���keyС����ұߵĿӣ�endλ�þ��γ��µĿ�
		a[begin] = a[end];
	}
	a[begin] = key;
	return begin;
}

//ǰ��ָ�뷨
int PartSort3(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);
	int prev = begin - 1;
	int cur = begin;
	int keyIndex = end;
	while (cur < end)
	{
		if (a[cur] < a[keyIndex] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[++prev], &a[cur]);
	return prev;
}


//����,��������ȡ�к��Ż���ʱ�临�Ӷȿ�����Ϊ��O(N*logN)
void QuickSort(int* a, int left, int right)
{
	assert(a);
	if (left >= right) return;
	if((right - left + 1) > 10)
	{
		int div = PartSort3(a, left, right);
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
	
	else
	{
		//С�ڵ���10�����ڵ����䣬���ٵݹ�����
		InsertSort(a + left, right - left + 1);
	}

}

//���ŷǵݹ�汾�����Ч�ʣ����ܷ�ֹϵͳջ̫֡��µ�ջ�����
/*void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);

	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);

		int div = PartSort3(a, begin, end);
		if (div + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, div + 1);
		}
		if (begin < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, begin);
		}
	}
	StackDestroy(&st);
}*/


void MergeArray(int* a, int begin1, int end1, int begin2, int end2, int* tmp)
{
	int left = begin1, right = end2;
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	//�ѹ鲢�õ�tmp�����ݿ�����ԭ����
	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	MergeArray(a, left, mid, mid + 1, right, tmp);
}
//�鲢����ʱ�临�Ӷ�ΪO(N*logN),�ռ临�Ӷ�ΪO(N)
void MergeSort(int* a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

//���ŷǵݹ�汾
void MergeSortNonR(int* a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int) * n);
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			
			/*���ϲ�ʱ����2��ż����ʱ����Ҫ�ޱ߽�*/
			//1���ϲ�ʱֻ��һ��ʱ������Ҫ�ϲ�
			if (begin2 >= n)
				break;
			
			//2���ϲ�ʱ�ڶ���ֻ�в�������,��Ҫ����end2�߽�
			if (end2 >= n)
				end2 = n - 1;

			MergeArray(a, begin1, end1, begin2, end2, tmp);
		}
		//PrintArray(a, n);
		gap *= 2;
	}
	free(tmp);
}
