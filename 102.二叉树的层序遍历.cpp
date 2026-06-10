#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if (root) que.push(root);

        while (que.size()) {
            vector<int> curLayer;
            vector<TreeNode*> nextLayer;
            while (que.size()) {
                TreeNode* front = que.front();
                que.pop();
                curLayer.push_back(front->val);
                if (front->left) nextLayer.push_back(front->left);
                if (front->right) nextLayer.push_back(front->right);
            }

            res.push_back(curLayer);
            for (int i = 0; i < nextLayer.size(); i++) que.push(nextLayer[i]);
        }

        return res;
    }
};
// @lc code=end
