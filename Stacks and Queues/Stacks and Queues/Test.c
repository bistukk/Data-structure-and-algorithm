#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
#include"Queue.h"

void TestStack1()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackTop(&st);
	printf("%d\n", StackTop(&st));
	StackDestroy(&st);
}

void TestStack2()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	printf("%d ", StackTop(&st));
	StackPop(&st);
	printf("%d\n", StackTop(&st));
	StackPop(&st);
	StackPush(&st, 5);
	StackPush(&st, 6);
	printf("%d\n", StackSize(&st));
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	StackDestroy(&st);
}

void TestQueue1()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	
	printf("%d\n", QueueBack(&q));
	printf("%d\n", QueueFront(&q));
	printf("%d\n", QueueSize(&q));

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);

	printf("%d\n", QueueSize(&q));

	QueueDestroy(&q);
}

void TestQueue2()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QDataType front = QueueFront(&q);
	printf("%d ", front);
	QueuePop(&q);

	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);
		printf("%d ", front);
		QueuePop(&q);
	}
	printf("\n");
}

int main()
{
	//TestStack1();
	//TestStack2();
	//TestQueue1();
	TestQueue2();
	return 0;
}