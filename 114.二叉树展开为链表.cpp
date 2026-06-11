#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = nullptr;

        if (left) root->right = dfs(left);
        TreeNode* lastNode = root;
        while (lastNode->right) lastNode = lastNode->right;
        if (right) lastNode->right = dfs(right);

        return root;
    }

    void flatten(TreeNode* root) {
        dfs(root);
    }
};
// @lc code=end



int main() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);

    node1->left = node2;
    node1->right = node5;
    node2->left = node3;
    node2->right = node4;
    node5->right = node6;

    Solution solution;
    solution.flatten(node1);
}