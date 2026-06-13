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
        int row_zero = 1, col_zero = 1;
        int n = matrix.size(), m = matrix[0].size();

        for (int i = 0; i < m; i++) {
            if (matrix[0][i] == 0) {
                row_zero = 0;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                col_zero = 0;
                break;
            }
        }

        cout << col_zero << " " << row_zero << endl;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }


        if (col_zero == 0) {
            for (int i = 0; i < n; i++) matrix[i][0] = 0;
        }
        if (row_zero == 0) {
            for (int i = 0; i < m; i++) matrix[0][i] = 0;
        }
    }
};
// @lc code=end
