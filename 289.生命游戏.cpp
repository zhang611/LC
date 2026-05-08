#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
class Solution {
   public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> prev = board;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = getNeighborSum(prev, i, j);
                if (prev[i][j] == 1) {
                    board[i][j] = (live == 2 || live == 3) ? 1 : 0;
                } else {
                    board[i][j] = (live == 3) ? 1 : 0;
                }
            }
        }
    }

    int getNeighborSum(const vector<vector<int>>& board, int x, int y) {
        int res = 0;

        for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; j++) {
                if (i == x && j == y) continue;
                if (i < 0 || i >= board.size()) continue;
                if (j < 0 || j >= board[0].size()) continue;
                res += board[i][j];
            }
        }

        return res;
    }
};
// @lc code=end
