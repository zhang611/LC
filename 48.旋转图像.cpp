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
        int start = 0, end = matrix.size() - 1;
        while (start < end) {
            int len = end - start;
            int t = end - start;
            while (t--) {
                int startValue = matrix[start][start];
                for (int row = start + 1; row <= end; row++)
                    matrix[row - 1][start] = matrix[row][start];
                for (int col = start + 1; col <= end; col++) 
                    matrix[end][col - 1] = matrix[end][col];
                for (int row = end - 1; row >= start; row--)
                    matrix[row + 1][end] = matrix[row][end];
                for (int col = end - 1; col >= start; col--)
                    matrix[start][col + 1] = matrix[start][col];
                matrix[start][start + 1] = startValue;
            }
            start++;
            end--;
        }
    }
};
// @lc code=end
