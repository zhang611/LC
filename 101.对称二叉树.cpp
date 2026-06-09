#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSame(root->left, root->right);
    }

    bool isSame(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (a && !b) return false;
        if (!a && b) return false;
        if (a->val != b->val) return false;

        bool outer = isSame(a->left, b->right);
        bool inner = isSame(a->right, b->left);
        return outer && inner;
    }
};
// @lc code=end
