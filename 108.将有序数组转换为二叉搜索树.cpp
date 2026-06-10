#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
    TreeNode* dfs(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;

        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = dfs(nums, l, mid - 1);
        node->right = dfs(nums, mid + 1, r);
        return node;
    }
};
// @lc code=end
