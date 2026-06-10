#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        bool left = isValidBST(root->left);
        bool right = isValidBST(root->right);

        if (!left || !right) return false;
        // 根比左边最大的大，比右边最小的小
        if (root->left) {
            TreeNode* maxLeft = root->left;
            while (maxLeft->right) maxLeft = maxLeft->right;
            if (root->val <= maxLeft->val) return false;
        }
        if (root->right) {
            TreeNode* maxRight = root->right;
            while (maxRight->left) maxRight = maxRight->left;
            if (root->val >= maxRight->val) return false;
        }

        return true;
    }
};
// @lc code=end
