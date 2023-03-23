#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//leetcode ��ָOffer40.��С��K����
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*void adjustDown(int* arr, int n, int root)
{
    int parent = root;
    int child = 2 * parent + 1;

    while (child < n)
    {
        if (child + 1 < n && arr[child] < arr[child + 1])
        {
            child++;
        }
        if (arr[parent] < arr[child])
        {
            int tmp = arr[parent];
            arr[parent] = arr[child];
            arr[child] = tmp;
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize) {
    *returnSize = k;
    //���K=0���򷵻ؿ�����
    if (k == 0)
    {
        return NULL;
    }
    int* retArr = (int*)malloc(sizeof(int) * k);
    int i = 0;
    //��K�����Ĵ�ѣ���ǰK������retArr
    for (i = 0; i < k; i++)
    {
        retArr[i] = arr[i];
    }
    //���ѣ����µ����������
    for (i = (k - 1 - 1) / 2; i >= 0; i--)
    {
        adjustDown(retArr, k, i);
    }
    //��ԭ������ʣ�µ����ͶѶ��Ƚϣ����С�ڶѶ����������
    for (i = k; i < arrSize; i++)
    {
        if (arr[i] < retArr[0])
        {
            retArr[0] = arr[i];
            adjustDown(retArr, k, 0);//���Ѻ����µ���һ�Σ����ִ��
        }
    }
    return retArr;
}*/



//leetcode 144. ��������ǰ�����
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
/*int TreeSize(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + TreeSize(root->left) + TreeSize(root->right);
}

void PrevOrder(struct TreeNode* root, int* arr, int* pi)
{
    if (root == NULL)
    {
        return;
    }
    arr[(*pi)++] = root->val;
    PrevOrder(root->left, arr, pi);
    PrevOrder(root->right, arr, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int k = TreeSize(root);
    int* arr = (int*)malloc(sizeof(int) * k);
    int i = 0;
    PrevOrder(root, arr, &i);
    *returnSize = k;
    return arr;
}*/




//leetcode 100. ��ͬ����
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;
    else if (p == NULL || q == NULL)
        return false;
    else if (p->val != q->val)
        return false;
    else
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}*/



//leetcode 226. ��ת������
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        struct TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
}*/




//leetcode ��ָ Offer 55 - I.�����������
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*int maxDepth(struct TreeNode* root) {
    if (root == NULL)
    {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}*/




//leetcode 965. ��ֵ������
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL)
        return true;
    if ((root->left != NULL && root->left->val != root->val) || (root->right != NULL && root->right->val != root->val))
        return false;
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}*/