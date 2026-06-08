#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {
public:
    struct Node {
        int val;
        Node* pre;
        Node* next;
        int key;
        Node(int value, int _key) : val(value), key(_key), next(nullptr), pre(nullptr) {}
    };

    int n = 0;
    Node* LL = new Node(-1, -1);
    Node* RR = new Node(-1, -1);
    unordered_map<int, Node*> umap;

    LRUCache(int capacity) {
        n = capacity;
        LL->next = RR;
        RR->pre = LL;
    }

    int get(int key) {
        if (umap.find(key) == umap.end()) return -1;

        Node* node = umap[key];

        node->pre->next = node->next;
        node->next->pre = node->pre;

        LL->next->pre = node;
        node->next = LL->next;
        LL->next = node;
        node->pre = LL;

        return node->val;
    }

    void put(int key, int value) {
        if (this->get(key) == -1) {
            // 没有，要加入，可能满了要删除
            if (umap.size() >= n) {
                Node* oldNode = RR->pre;
                RR->pre->pre->next = RR;
                RR->pre = RR->pre->pre;
                umap.erase(oldNode->key);
            }

            Node* newNode = new Node(value, key);
            LL->next->pre = newNode;
            newNode->next = LL->next;
            LL->next = newNode;
            newNode->pre = LL;
            umap[key] = newNode;

        } else {
            umap[key]->val = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
