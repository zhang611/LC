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
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> st(n, vector<bool>(m, false));

        int size = n * m;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;
        int cur_x = 0, cur_y = 0;
        while (size--) {
            res.push_back(matrix[cur_x][cur_y]);
            st[cur_x][cur_y] = true;
            int ne_x = cur_x + dirs[dir][0];
            int ne_y = cur_y + dirs[dir][1];
            if (ne_x < 0 || ne_x >= n || ne_y < 0 || ne_y >= m || st[ne_x][ne_y] == true) {
                dir = (dir + 1) % 4;
                ne_x = cur_x + dirs[dir][0];
                ne_y = cur_y + dirs[dir][1];
            }
            cur_x = ne_x;
            cur_y = ne_y;
        }
        return res;
    }
};
// @lc code=end
