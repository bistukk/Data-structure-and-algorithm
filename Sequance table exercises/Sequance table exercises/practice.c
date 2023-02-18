#define _CRT_SECURE_NO_WARNINGS 1

//leetcode面试题 17.04. 消失的数字
//int missingNumber(int* nums, int numsSize) {
//    int i = 0;
//    int flag = 0;
//    for (i = 0; i <= numsSize; i++)
//    {
//        flag ^= i;
//    }
//    for (i = 0; i < numsSize; i++)
//    {
//        flag ^= *(nums + i);
//    }
//    return flag;
//}


//剑指 Offer 56 - I.数组中数字出现的次数
//int* singleNumbers(int* nums, int numsSize, int* returnSize) {
//    //1.将所有数字异或
//    int ret = 0;
//    int pos = 0;
//    int i = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        ret ^= nums[i];
//    }
//
//    //2.拿到不同位的位置
//    for (i = 0; i < 32; i++)
//    {
//        //拿到一个数的第i位
//        if ((ret >> i) & 1 == 1)
//        {
//            pos = i;
//            break;
//        }
//    }
//    //printf("%d",pos);
//    //3.将两个只出现一次的数字分组
//    int num1 = 0;
//    int num2 = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        if ((nums[i] >> pos) & 1 == 1)
//        {
//            num1 ^= nums[i];
//        }
//        else
//        {
//            num2 ^= nums[i];
//        }
//    }
//    printf("%d %d", num1, num2);
//    //4.将两个数存入数组中并输出
//    int* arr = (int*)malloc(sizeof(int) * 2);
//    arr[0] = num1;
//    arr[1] = num2;
//    *returnSize = 2;
//    return arr;
//}


//189. 轮转数组
////写一个反转函数
//void roll(int* left, int* right)
//{
//    while (left < right)
//    {
//        int tmp = *left;
//        *left = *right;
//        *right = tmp;
//        ++left;
//        --right;
//    }
//}
//
//void rotate(int* nums, int numsSize, int k) {
//    //三步反转法
//    k %= numsSize;//重要取模，防止溢出
//    roll(nums + numsSize - k, nums + numsSize - 1);
//    roll(nums, nums + numsSize - k - 1);
//    roll(nums, nums + numsSize - 1);
//    return nums;
//}


//26. 删除有序数组中的重复项
//int removeDuplicates(int* nums, int numsSize) {
//    if (numsSize == 0)
//        return 0;
//    int fast = 1;
//    int slow = 0;
//    int k = 1;
//    while (fast < numsSize)
//    {
//        if (nums[slow] != nums[fast])
//        {
//            slow++;
//            nums[slow] = nums[fast];
//            fast++;
//            k++;
//        }
//        else
//        {
//            fast++;
//        }
//    }
//    return k;
//}


//27. 移除元素
//int removeElement(int* nums, int numsSize, int val) {
//    int dst = 0;
//    int src = 0;
//    while (src < numsSize)
//    {
//        if (nums[src] != val)
//        {
//            nums[dst] = nums[src];
//            dst++;
//        }
//        ++src;
//    }
//    return dst;
//}


