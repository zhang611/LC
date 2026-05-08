
using namespace std;
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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
        ListNode* result = new ListNode(0);
        ListNode* cur = result;

        while (l1 || l2) {
            if (l1) t += l1->val;
            if (l2) t += l2->val;

            cur = cur->next = new ListNode(t % 10);
            t /= 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if (t) cur = cur->next = new ListNode(t);

        return result->next;
    }
};
// @lc code=end
