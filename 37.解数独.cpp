#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    bool col[9][9], row[9][9], cell[3][3][9];

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int x = board[i][j] - '1';
                row[i][x] = col[j][x] = cell[i / 3][j / 3][x] = true;
            }
        }
        dfs(board, 0, 0);
    }

    bool dfs(vector<vector<char>>& board, int x, int y) {
        if (y == 9) x++, y = 0;
        if (x == 9) return true;
        if (board[x][y] != '.') return dfs(board, x, y + 1);

        for (int i = 0; i < 9; i++) {
            if (row[x][i] || col[y][i] || cell[x / 3][y / 3][i]) continue;
            row[x][i] = col[y][i] = cell[x / 3][y / 3][i] = true;
            board[x][y] = i + '1';
            if (dfs(board, x, y + 1)) return true;
            board[x][y] = '.';
            row[x][i] = col[y][i] = cell[x / 3][y / 3][i] = false;
        }
        return false;
    }
};
// @lc code=end
