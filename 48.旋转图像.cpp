#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        n /= 2;

        int start = 0;
        int end = matrix.size() - 1;
        while (n--) {
            int rotation_num = end - start;
            while (rotation_num--) {
                int first_num = matrix[start][start];
                for (int i = start + 1; i <= end; i++) matrix[i - 1][start] = matrix[i][start];
                for (int i = start + 1; i <= end; i++) matrix[end][i - 1] = matrix[end][i];
                for (int i = end - 1; i >= start; i--) matrix[i + 1][end] = matrix[i][end];
                for (int i = end - 1; i >= start; i--) matrix[start][i + 1] = matrix[start][i];
                matrix[start][start + 1] = first_num;
            }

            start++;
            end--;
        }
    }
};
// @lc code=end
