#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> col, row;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    col.insert(i);
                    row.insert(j);
                }
            }
        }

        for (auto x : col) {
            for (int i = 0; i < matrix[0].size(); i++) matrix[x][i] = 0;
        }
        for (auto x : row) {
            for (int i = 0; i < matrix.size(); i++) matrix[i][x] = 0;
        }
    }
};
// @lc code=end
