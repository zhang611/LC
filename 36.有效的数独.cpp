#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            unordered_set<char> hash;
            for (int j = 0; j < board[0].size(); j++) {
                if (hash.find(board[i][j]) != hash.end()) return false;
                if (board[i][j] != '.') hash.insert(board[i][j]);
            }
            hash.clear();
        }

        for (int i = 0; i < board.size(); i++) {
            unordered_set<char> hash;
            for (int j = 0; j < board[0].size(); j++) {
                if (hash.find(board[j][i]) != hash.end()) return false;
                if (board[j][i] != '.') hash.insert(board[j][i]);
            }
            hash.clear();
        }

        for (int i = 0; i < board.size(); i++) {
            unordered_set<char> hash;
            for (int j = 0; j < board[0].size(); j++) {
                int m = j / 3 + i / 3 * 3;
                int n = j % 3 + i % 3 * 3;

                if (hash.find(board[m][n]) != hash.end()) return false;
                if (board[m][n] != '.') hash.insert(board[m][n]);
            }
        }

        return true;
    }
};
// @lc code=end
