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

//插入排序(时间复杂度为：O(N~2))
//鎻掑叆鎺掑簭(鏃堕棿澶嶆潅搴︿负锛歄(N~2))
void InsertSort(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n - 1; i++)//娉ㄦ剰杈圭晫鏄痭-1,鍥犱负鏄粠0 鍒?n-2鎻掑叆
	{
		//鎶奺nd + 1鎻掑叆[0 - end]鐨勬湁搴忓尯闂?
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

//甯屽皵鎺掑簭(鏃堕棿澶嶆潅搴︿负锛歄(N~1.3 - N~2))
void ShellSort(int* a, int n)
{
	assert(a);

	int gap = n;
	while (gap > 1)
	{
		//gap > 1鏃惰鏁扮粍鎺ヨ繎鏈夊簭
		//gap == 1鏃剁浉褰撲簬涓�韬虹洿鎺ユ彃鍏ユ帓搴忥紝淇濊瘉鏈夊簭
		gap = gap / 3 + 1;// +1淇濊瘉浜嗘渶鍚庝竴娆′竴瀹氭槸1
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

//閫夋嫨鎺掑簭(鏃堕棿澶嶆潅搴︽槸O(N~2))
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
		
		//濡傛灉鍑虹幇閲嶅彔鐨勬儏鍐? 鍒欓渶鎶妋axi鐨勪綅缃慨姝ｏ紝闃叉鍙堟崲鍥炴潵
		if (maxi == begin)
		{
			maxi = mini;
		} 
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

//鍫嗘帓搴?
//鍚戜笅璋冩暣娉?
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
//鏃堕棿澶嶆潅搴(log(N))
void HeapSort(int* a, int n)
{
	//鎺掑崌搴忥紝寤哄ぇ鍫?
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

//鍐掓场鎺掑簭(鏃堕棿澶嶆潅搴︿负:O(N~2)
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

		//浼樺寲: 濡傛灉涓�韬哄啋娉℃帓搴忔病鏈夊彂鐢熶氦鎹紝鍒欒鏄庡凡缁忔湁搴?
		if (exchange == 0)
		{
			break;
		}
		--end;
	}
}


//三数取中，让最坏的情况不会再出现
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

//左右指针法
int PartSort1(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);
	int keyIndex = end;
	while (begin < end)
	{
		//begin找大
		while (begin < end && a[begin] <= a[keyIndex])
		{
			++begin;
		}

		//end找小
		while (begin < end && a[end] >= a[keyIndex])
		{
			--end;
		}

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyIndex]);

	return begin;
}

//挖坑法
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

		//左边找到比key大的填到右边的坑，begin位置就形成新的坑
		a[end] = a[begin];

		while (begin < end && a[end] >= key)
		{
			--end;
		}

		//右边找到比key小的填到右边的坑，end位置就形成新的坑
		a[begin] = a[end];
	}
	a[begin] = key;
	return begin;
}

//前后指针法
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


//快排,经过三数取中和优化后，时间复杂度可以认为是O(N*logN)
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
		//小于等于10个以内的区间，不再递归排序
		InsertSort(a + left, right - left + 1);
	}

}

//快排非递归版本，提高效率，且能防止系统栈帧太深导致的栈溢出。
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

	//把归并好的tmp的数据拷贝回原数组
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
//归并排序，时间复杂度为O(N*logN),空间复杂度为O(N)
void MergeSort(int* a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

//快排非递归版本
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
			
			/*当合并时不是2的偶数倍时，需要修边界*/
			//1、合并时只有一组时，不需要合并
			if (begin2 >= n)
				break;
			
			//2、合并时第二组只有部分数据,需要修正end2边界
			if (end2 >= n)
				end2 = n - 1;

			MergeArray(a, begin1, end1, begin2, end2, tmp);
		}
		//PrintArray(a, n);
		gap *= 2;
	}
	free(tmp);
}
