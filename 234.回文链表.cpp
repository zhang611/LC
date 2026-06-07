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
        int n = 0;
        for (auto i = head; i != nullptr; i = i->next) n++;
        if (n == 1) return true;

        ListNode* headA = head;
        ListNode* headB = head;
        ListNode* lastA = head;
        for (int i = 0; i < n / 2 - 1; i++) lastA = lastA->next;
        if (n % 2 == 1) headB = lastA->next->next;
        else headB = lastA->next;
        lastA->next = nullptr;

        // 反转a
        ListNode* a = nullptr;
        ListNode* b = headA;
        while (b) {
            ListNode* c = b->next;
            b->next = a;
            a = b;
            b = c;
        }

        headA = a;

        while (headA && headB) {
            if (headA->val != headB->val) return false;
            headA = headA->next;
            headB = headB->next;
        }
        return true;
    }
};
// @lc code=end
