#define _CRT_SECURE_NO_WARNINGS 1

//Leetcode203. 移除链表元素
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* cur = head;
//    struct ListNode* prev = (struct ListNode*)malloc(sizeof(struct ListNode));
//    prev->next = head;
//    while (cur != NULL)
//    {
//        if (cur->val == val)
//        {
//            if (cur == head)
//            {
//                head = cur->next;
//            }
//            prev->next = cur->next;
//            free(cur);
//            cur = prev->next;
//        }
//        else
//        {
//            cur = cur->next;
//            prev = prev->next;
//        }
//    }
//    return head;
//}


//牛客CM11 链表分割
///*
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};*/
//
//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x) {
//        // write code here
//        //创建两个链表，一个存大的，一个存小的
//        ListNode* greaterhead, * greatertail, * lesshead, * lesstail;
//        greaterhead = greatertail = (ListNode*)malloc(sizeof(ListNode));
//        lesshead = lesstail = (ListNode*)malloc(sizeof(ListNode));
//        ListNode* cur = pHead;
//        while (cur)
//        {
//            if (cur->val < x)
//            {
//                lesstail->next = cur;
//                lesstail = lesstail->next;
//            }
//            else
//            {
//                greatertail->next = cur;
//                greatertail = greatertail->next;
//            }
//            cur = cur->next;
//        }
//        greatertail->next = NULL;
//        lesstail->next = greaterhead->next;
//        return lesshead->next;
//    }
//};


//leetcode 21.合并两个有序链表
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* cur = dummy;
//    while (list1 && list2)
//    {
//        if (list1->val < list2->val)
//        {
//            cur->next = list1;
//            list1 = list1->next;
//            cur = cur->next;
//        }
//        else
//        {
//            cur->next = list2;
//            list2 = list2->next;
//            cur = cur->next;
//        }
//    }
//    cur->next = list1 == NULL ? list2 : list1;
//    return dummy->next;
//}


//牛客 链表中倒数第k个结点
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//    // write code here
//    struct ListNode* fast = pListHead;
//    struct ListNode* slow = pListHead;
//    while (k--)
//    {
//        if (fast == NULL)
//        {
//            return NULL;
//        }
//        fast = fast->next;
//    }
//    while (fast)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    return slow;
//}


//leetcode 876.链表的中间结点
//struct ListNode* middleNode(struct ListNode* head) {
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
//}


//leetcode 206. 反转链表
//struct ListNode* reverseList(struct ListNode* head) {
//    struct ListNode* prev = NULL;
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//        cur->next = prev;
//        prev = cur;
//        cur = next;
//    }
//    return prev;
//}


//leetcode 142. 环形链表 II
//struct ListNode* detectCycle(struct ListNode* head) {
//    //快慢指针先找到圈内相遇点
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//        {
//            struct ListNode* meetnode = slow;
//            //从相遇点和头开始一起走，两者相遇时即为入环点
//            while (head != meetnode)
//            {
//                head = head->next;
//                meetnode = meetnode->next;
//            }
//            return meetnode;
//        }
//    }
//    return NULL;
//}


//leetcode 141. 环形链表
//bool hasCycle(struct ListNode* head) {
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//        {
//            return true;
//        }
//    }
//    return false;
//}


//leetcode 160. 相交链表
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    struct ListNode* curA = headA;
//    struct ListNode* curB = headB;
//    if (curA == NULL || curB == NULL)
//    {
//        return NULL;
//    }
//    while (curA != curB)
//    {
//        curA = curA == NULL ? headB : curA->next;
//        curB = curB == NULL ? headA : curB->next;
//    }
//    return curA;
//}


//牛客 OR36 链表的回文结构
//struct ListNode* middleNode(struct ListNode* head) {
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
//}
//
//struct ListNode* reverseList(struct ListNode* head) {
//    struct ListNode* prev = NULL;
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        //当cur不为空时创建next,这样可以防止越界
//        struct ListNode* next = cur->next;
//        cur->next = prev;
//        prev = cur;
//        cur = next;
//    }
//    return prev;
//}
//
//class PalindromeList {
//public:
//    bool chkPalindrome(ListNode* A) {
//        // write code here
//        //用快慢指针找到中间节点
//        struct ListNode* mid = middleNode(A);
//        struct ListNode* rHead = reverseList(mid);
//        while (rHead && A)
//        {
//            if (rHead->val != A->val)
//            {
//                return false;
//            }
//            else
//            {
//                rHead = rHead->next;
//                A = A->next;
//            }
//        }
//        return true;
//    }
//};

