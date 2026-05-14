#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        int n = 0;
        ListNode* cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }
        if (n < 2)
            return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* a = dummy;

        while (a->next && a->next->next) {
            ListNode* b = a->next;
            ListNode* c = a->next->next;
            ListNode* d = a->next->next->next;

            a->next = c;
            c->next = b;
            b->next = d;
            a = b;
        }

        return dummy->next;
    }
};
// @lc code=end
