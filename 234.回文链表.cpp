#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        int len = 0;
        for (auto i = head; i != nullptr; i = i->next) len++;

        if (len % 2) len = len / 2 + 1;
        else len = len / 2;

        ListNode* head2 = head;
        while (len--) head2 = head2->next;

        ListNode* a = nullptr;
        ListNode* b = head2;
        while (b) {
            ListNode* c = b->next;
            b->next = a;

            a = b;
            b = c;
        }

        while (a) {
            if (a->val != head->val) return false;
            a = a->next;
            head = head->next;
        }
        return true;
    }
};
// @lc code=end
