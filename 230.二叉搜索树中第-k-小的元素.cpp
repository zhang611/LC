#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
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
    int index;

    int kthSmallest(TreeNode* root, int k) {
        index = k;
        int res = dfs(root);
        return res;
    }

    int dfs(TreeNode* node) {
        if (node == nullptr) return INT_MAX;

        int l = dfs(node->left);
        if (l != INT_MAX) return l;

        if (--index == 0) return node->val;

        int r = dfs(node->right);
        if (r != INT_MAX) return r;

        return INT_MAX;
    }
};
// @lc code=end
