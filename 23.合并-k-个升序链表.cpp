#include "leetcode_local.hpp"
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

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
    struct MCP {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, MCP> heap;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i])
                heap.push(lists[i]);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (heap.size()) {
            ListNode* temp = heap.top();
            cur = cur->next = temp;
            heap.pop();
            if (temp->next)
                heap.push(temp->next);
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