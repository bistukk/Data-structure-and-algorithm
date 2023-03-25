#define _CRT_SECURE_NO_WARNINGS 1
# include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->_data);
	PrevOrder(root->_left);
	PrevOrder(root->_right); 
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%c ", root->_data);
}

int TreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
	    return 1 + TreeSize(root->_left) + TreeSize(root->_right);
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}


BTNode* CreateNode(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		return;
	}
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;
}

//二叉树第K层节点
 int BinaryTreeLevelKSize(BTNode* root, int k)
 {
	 if (root == NULL)
		 return 0;
	 if (k == 1)
		 return 1;
	 return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
 }

 //二叉树查找值为x的节点
 BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
 {
	 if (root == NULL)
		 return NULL;
	 if (root->_data == x)
		 return root;
	 BTNode* node = BinaryTreeFind(root->_left, x);
	 if (node)
		 return node;
	 node = BinaryTreeFind(root->_right, x);
	 if (node)
		 return node;
	 return NULL;
 }

 //销毁树
 void DestroyTree(BTNode* root)
 {
	 if (root == NULL)
		 return;
	 DestroyTree(root->_left);
	 DestroyTree(root->_right);
	 free(root);
 }

 //层序遍历(利用栈的先进先出，出一个带两个)
 /*
 void BinaryTreeLevelOrder(BTNode* root)
 {
	 Queue q;
	 if (root == NULL)
		 return;
	 QueueInit(&q);
	 QueuePush(&q, root);
	 while (!QueueEmpty(&q))
	 {
		 BTNode* front = QueueFront(&q);
		 QueuePop(&q);
		 printf("%c ", front->_data);
		 if(front->_left)
		 {
			 QueuePush(&q, front->_left);
		 }
		 if (front->_right)
		 {
			 QueuePush(&Q, front->_right);
		 }
	 }
	 QueueDestroy(&q);
	 printf("\n");
 }
 */

 //判断树是否是完全二叉树
 //是，返回1，不是返回0
/*
(利用层序遍历思想)
int BinaryTreeComplete(BTNode* root)
 {
	 Queue q;
	 QueueInit(&q);
	 if (root == NULL)
		 return 1;

	 QueuePush(&q, root);

	 while (!QueueEmpty(&q))
	 {
		 BTNode* front = QueueFront(&q);
		 QueuePop(&q);
		 if (front == NULL)
		 {
			 break;//出来一个空就跳出
		 }
		 QueuePush(&q, front->_left);
		 QueuePush(&q, front->_right);
	 }

	 //检查剩下队列是否全为空
	 while(!QueueEmpty(&q))
	 {
		 BTNode* front = QueueFront(&q);
		 QueuePop(&q);
		 if (front)
		 {
			 QueueDestroy(&q);//注意销毁，防止内存泄漏
			 return 0;
		 }
	 }
	 return 1;
 }
 */

int main()
{
	BTNode* A = CreateNode('A');
	BTNode* B = CreateNode('B');
	BTNode* C = CreateNode('C');
	BTNode* D = CreateNode('D');
	BTNode* E = CreateNode('E');
	A->_left = B;
	A->_right = C;
	B->_left = D;
	B->_right = E;
	PrevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\nTreeSize: %d\n", TreeSize(A));
	printf("TreeLeafSize: %d\n", TreeLeafSize(A));
	printf("BinaryTreeLevelKSize: %d\n", BinaryTreeLevelKSize(A,3));
	return 0;
}