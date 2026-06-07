#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int t = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (l1 && l2) {
            int x = l1->val + l2->val + t;
            cur = cur->next = new ListNode(x % 10);
            t = x / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            t += l1->val;
            cur = cur->next = new ListNode(t % 10);
            t /= 10;
            l1 = l1->next;
        }

        while (l2) {
            t += l2->val;
            cur = cur->next = new ListNode(t % 10);
            t /= 10;
            l2 = l2->next;
        }

        if (t) cur->next = new ListNode(t);

        return dummy->next;
    }
};
// @lc code=end
