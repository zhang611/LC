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
        ListNode* cur = dummy;

        while (1) {
            ListNode* st = cur->next;
            ListNode* ed = cur;
            for (int i = 0; i < k; i++) {
                if (ed) ed = ed->next;
            }
            if (ed == nullptr) break;

            ListNode* a = cur->next;
            ListNode* b = cur->next->next;
            for (int i = 0; i < k - 1; i++) {
                ListNode* c = b->next;
                b->next = a;
                a = b;
                b = c;
            }
            cur->next->next = b;
            cur->next = a;
            cur = st;
        }
        return dummy->next;
    }
};
// @lc code=end

// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode *dummy = new ListNode(-1);
//         dummy->next = head;
//         ListNode *cur = dummy;

//         while(1) {
//             int n = k;
//             ListNode *end = cur;
//             ListNode *st = cur->next;
//             while(n--) {
//                 if (end) end = end->next;
//             }
//             if (end == nullptr) break;

//             ListNode *a = cur->next, *b = cur->next->next;
//             int cnt = k - 1;
//             while(cnt--) {
//                 ListNode *t = b->next;
//                 b->next = a;
//                 a = b;
//                 b = t;
//             }
//             cur->next->next = b;
//             cur->next = a;
//             cur = st;

//         }
//         return dummy->next;

//     }
// };