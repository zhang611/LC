#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* a = dummy;
        ListNode* b = head;
        while (b) {
            ListNode* c = a;
            for (int i = 0; i < k; i++) {
                if (!c->next) return dummy->next;
                else c = c->next;
            }
            ListNode* d = c->next;

            // 内部翻转
            ListNode* ta = nullptr;
            ListNode* tb = b;
            while (ta != c) {
                ListNode* tc = tb->next;
                tb->next = ta;
                ta = tb;
                tb = tc;
            }

            a->next = c;
            b->next = d;

            a = b;
            b = d;
        }
        return dummy->next;
    }
};
// @lc code=end
