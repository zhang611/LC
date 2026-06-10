#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        if (root) que.push(root);

        while (que.size()) {
            int s = que.size();
            int layerLastValue = que.front()->val;
            for (int i = 0; i < s; i++) {
                TreeNode* front = que.front();
                que.pop();
                if (front->left) que.push(front->left);
                if (front->right) que.push(front->right);
                layerLastValue = front->val;
            }
            res.push_back(layerLastValue);
        }

        return res;
    }
};
// @lc code=end
