#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newDummy = new Node(-1);
        Node* cur = newDummy;

        unordered_map<Node*, Node*> umap;

        for (auto i = head; i != nullptr; i = i->next) {
            cur = cur->next = new Node(i->val);
            umap[i] = cur;
        }

        for (auto i = head, j = newDummy->next; i != nullptr; i = i->next, j = j->next) {
            j->random = umap[i->random];
        }
        return newDummy->next;
    }
};
// @lc code=end

// 用哈希表模拟应该可以实现，不知道有没有更好的办法