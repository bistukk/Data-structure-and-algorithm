#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

<<<<<<< HEAD
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//²åÈëÅÅĞò(Ê±¼ä¸´ÔÓ¶ÈÎª£ºO(N~2))
=======
//æ’å…¥æ’åº(æ—¶é—´å¤æ‚åº¦ä¸ºï¼šO(N~2))
>>>>>>> a11e5f3f0a89ad44d2ff253cc36822a01f838fce
void InsertSort(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n - 1; i++)//æ³¨æ„è¾¹ç•Œæ˜¯n-1,å› ä¸ºæ˜¯ä»0 åˆ° n-2æ’å…¥
	{
		//æŠŠend + 1æ’å…¥[0 - end]çš„æœ‰åºåŒºé—´
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

//å¸Œå°”æ’åº(æ—¶é—´å¤æ‚åº¦ä¸ºï¼šO(N~1.3 - N~2))
void ShellSort(int* a, int n)
{
	assert(a);

	int gap = n;
	while (gap > 1)
	{
		//gap > 1æ—¶è®©æ•°ç»„æ¥è¿‘æœ‰åº
		//gap == 1æ—¶ç›¸å½“äºä¸€èººç›´æ¥æ’å…¥æ’åºï¼Œä¿è¯æœ‰åº
		gap = gap / 3 + 1;// +1ä¿è¯äº†æœ€åä¸€æ¬¡ä¸€å®šæ˜¯1
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

//é€‰æ‹©æ’åº(æ—¶é—´å¤æ‚åº¦æ˜¯O(N~2))
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
		
		//å¦‚æœå‡ºç°é‡å çš„æƒ…å†µ, åˆ™éœ€æŠŠmaxiçš„ä½ç½®ä¿®æ­£ï¼Œé˜²æ­¢åˆæ¢å›æ¥
		if (maxi == begin)
		{
			maxi = mini;
		} 
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

//å †æ’åº
//å‘ä¸‹è°ƒæ•´æ³•
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
//æ—¶é—´å¤æ‚åº¦O(log(N))
void HeapSort(int* a, int n)
{
	//æ’å‡åºï¼Œå»ºå¤§å †
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

//å†’æ³¡æ’åº(æ—¶é—´å¤æ‚åº¦ä¸º:O(N~2)
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

		//ä¼˜åŒ–: å¦‚æœä¸€èººå†’æ³¡æ’åºæ²¡æœ‰å‘ç”Ÿäº¤æ¢ï¼Œåˆ™è¯´æ˜å·²ç»æœ‰åº
		if (exchange == 0)
		{
			break;
		}
		--end;
	}
}
<<<<<<< HEAD

//ÈıÊıÈ¡ÖĞ£¬ÈÃ×î»µµÄÇé¿ö²»»áÔÙ³öÏÖ
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

//×óÓÒÖ¸Õë·¨
int PartSort1(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);
	int keyIndex = end;
	while (begin < end)
	{
		//beginÕÒ´ó
		while (begin < end && a[begin] <= a[keyIndex])
		{
			++begin;
		}

		//endÕÒĞ¡
		while (begin < end && a[end] >= a[keyIndex])
		{
			--end;
		}

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyIndex]);

	return begin;
}

//ÍÚ¿Ó·¨
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

		//×ó±ßÕÒµ½±Èkey´óµÄÌîµ½ÓÒ±ßµÄ¿Ó£¬beginÎ»ÖÃ¾ÍĞÎ³ÉĞÂµÄ¿Ó
		a[end] = a[begin];

		while (begin < end && a[end] >= key)
		{
			--end;
		}

		//ÓÒ±ßÕÒµ½±ÈkeyĞ¡µÄÌîµ½ÓÒ±ßµÄ¿Ó£¬endÎ»ÖÃ¾ÍĞÎ³ÉĞÂµÄ¿Ó
		a[begin] = a[end];
	}
	a[begin] = key;
	return begin;
}

//Ç°ºóÖ¸Õë·¨
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


//¿ìÅÅ,¾­¹ıÈıÊıÈ¡ÖĞºÍÓÅ»¯ºó£¬Ê±¼ä¸´ÔÓ¶È¿ÉÒÔÈÏÎªÊÇO(N*logN)
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
		//Ğ¡ÓÚµÈÓÚ10¸öÒÔÄÚµÄÇø¼ä£¬²»ÔÙµİ¹éÅÅĞò
		InsertSort(a + left, right - left + 1);
	}

}

//¿ìÅÅ·Çµİ¹é°æ±¾£¬Ìá¸ßĞ§ÂÊ£¬ÇÒÄÜ·ÀÖ¹ÏµÍ³Õ»Ö¡Ì«Éîµ¼ÖÂµÄÕ»Òç³ö¡£
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





=======
>>>>>>> a11e5f3f0a89ad44d2ff253cc36822a01f838fce
