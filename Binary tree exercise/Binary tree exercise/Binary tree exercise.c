#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//leetcode 剑指Offer40.最小的K个数
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
    //如果K=0，则返回空数组
    if (k == 0)
    {
        return NULL;
    }
    int* retArr = (int*)malloc(sizeof(int) * k);
    int i = 0;
    //建K的数的大堆，先前K个拷入retArr
    for (i = 0; i < k; i++)
    {
        retArr[i] = arr[i];
    }
    //建堆，向下调整法建大堆
    for (i = (k - 1 - 1) / 2; i >= 0; i--)
    {
        adjustDown(retArr, k, i);
    }
    //将原数组中剩下的数和堆顶比较，如果小于堆顶数，则进堆
    for (i = k; i < arrSize; i++)
    {
        if (arr[i] < retArr[0])
        {
            retArr[0] = arr[i];
            adjustDown(retArr, k, 0);//进堆后向下调整一次，保持大堆
        }
    }
    return retArr;
}*/



//leetcode 144. 二叉树的前序遍历
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




//leetcode 100. 相同的树
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



//leetcode 226. 翻转二叉树
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




//leetcode 剑指 Offer 55 - I.二叉树的深度
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




//leetcode 965. 单值二叉树
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




//leetcode 572. 另一棵树的子树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
        return true;
    else if (p == NULL || q == NULL)
        return false;
    else if (p->val != q->val)
        return false;
    else
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL)
        return false;
    if (isSameTree(root, subRoot))
        return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
*/




//leetcode 剑指 Offer 28. 对称的二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
bool check(struct TreeNode* p, struct TreeNode* q)
{
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;
    return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
    return check(root, root);
}
*/




//leetcode 110. 平衡二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
方法一：
int TreeDepth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    int leftDepth = TreeDepth(root->left);
    int rightDepth = TreeDepth(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }
    int gap = TreeDepth(root->left) - TreeDepth(root->right);
    return  abs(gap) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}
*/

/*
方法二：
 //优化版本（后续遍历）,时间复杂度最坏为O（N）
    bool _isBalanced(struct TreeNode* root, int* pDepth)
{
    //给个指针，每判断一次就带回返回值
    if (root == NULL)
    {
        *pDepth = 0;
        return true;
    }
    else
    {
        int leftDepth = 0;
        int rightDepth = 0;
        if ((!_isBalanced(root->left, &leftDepth)) || (!_isBalanced(root->right, &rightDepth)))
            return false;
        if (abs(leftDepth - rightDepth) > 1)
            return false;
        *pDepth = (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
        return true;
    }
}

bool isBalanced(struct TreeNode* root) {
    int Depth = 0;
    return _isBalanced(root, &Depth);
}
*/




//牛客网 清华大学计算机历年考研复试 [编程题]二叉树遍历
/*
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct TreeNode {
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* CreateTree(char* str, int* pi)
{
    if (str[*pi] == '#')
    {
        ++(*pi);
        return NULL;
    }
    else
    {
        TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
        root->val = str[*pi];
        ++(*pi);
        root->left = CreateTree(str, pi);
        root->right = CreateTree(str, pi);
        return root;
    }
}

void InOrderTree(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    InOrderTree(root->left);
    printf("%c ", root->val);
    InOrderTree(root->right);
}

int main() {
    char str[101] = { 0 };
    scanf("%s", str);
    int i = 0;
    TreeNode* root = CreateTree(str, &i);
    InOrderTree(root);
    return 0;
}
*/