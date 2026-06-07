#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = 0;
        for (auto i = headA; i != nullptr; i = i->next) lenA++;
        int lenB = 0;
        for (auto i = headB; i != nullptr; i = i->next) lenB++;

        int gap = abs(lenA - lenB);
        if (lenA > lenB)
            while (gap--) headA = headA->next;
        else
            while (gap--) headB = headB->next;

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};
// @lc code=end
