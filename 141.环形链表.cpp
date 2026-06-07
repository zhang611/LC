#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode* head) {
        if (head == nullptr) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while (true) {
            if (fast->next == nullptr) return false;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == nullptr || slow == nullptr) return false;
            if (fast == slow) return true;
        }
        return false;
    }
};
// @lc code=end
