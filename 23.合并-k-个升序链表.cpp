#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */

// @lc code=start
// Definition for singly-linked list.

// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next) : val(x), next(next) {}
// };

class Solution {
public:
    struct compare {
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (int i = 0; i < lists.size(); i++) {
            pq.push(lists[i]);
            lists[i] = lists[i]->next;
        }

        while (pq.size()) {
            ListNode* top = pq.top();
            pq.pop();
            cur = cur->next = top;
            if (top->next) pq.push(top->next);
        }
        return dummy->next;
    }
};
// @lc code=end

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:

//     struct CMP {
//         bool operator() (ListNode* a, ListNode* b) {
//             return a->val > b->val;
//         }
//     };

//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         priority_queue<ListNode*, vector<ListNode*>, CMP> heap;
//         for (int i = 0; i < lists.size(); i++) {
//             if (lists[i]) heap.push(lists[i]);
//         }

//         ListNode* dummy = new ListNode(-1), *cur = dummy;
//         while(heap.size()) {
//             auto temp = heap.top();
//             cur = cur->next = temp;
//             heap.pop();
//             if (temp->next) heap.push(temp->next);
//         }
//         return dummy->next;
//     }

// };