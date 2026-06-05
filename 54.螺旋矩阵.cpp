#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        vector<vector<bool>> st(matrix.size(), vector<bool>(matrix[0].size(), false));
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int x = 0, y = 0;
        int size = matrix.size() * matrix[0].size();
        int dir = 0;
        while (size--) {
            res.push_back(matrix[x][y]);
            st[x][y] = true;
            int i = x + dirs[dir][0];
            int j = y + dirs[dir][1];
            if (i >= matrix.size() || j >= matrix[0].size() || i < 0 || j < 0 || st[i][j] == true) {
                dir = (dir + 1) % 4;
                i = x + dirs[dir][0];
                j = y + dirs[dir][1];
            }
            x = i;
            y = j;
        }
        return res;
    }
};
// @lc code=end
