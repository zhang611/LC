#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    vector<int> pre, in;
    unordered_map<int, int> pre_index;
    unordered_map<int, int> in_index;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        in = inorder;
        for (int i = 0; i < preorder.size(); i++) pre_index[preorder[i]] = i;
        for (int i = 0; i < inorder.size(); i++) in_index[inorder[i]] = i;

        return dfs(0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* dfs(int pl, int pr, int il, int ir) {
        if (pl > pr || il > ir) return nullptr;

        TreeNode* node = new TreeNode(pre[pl]);
        int value = node->val;
        int inorder_index = in_index[value];

        node->left = dfs(pl + 1, pl + 1 + inorder_index -1 - il, il, inorder_index - 1);
        node->right = dfs(pl + 1 + inorder_index - 1 - il + 1, pr, inorder_index + 1, ir);

        return node;
    }
};
// @lc code=end
