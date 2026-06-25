#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        vector<vector<bool>> st(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (st[i][j]) continue;
                if (grid[i][j] == '0') continue;

                queue<pair<int, int>> que;
                res++;
                que.push({i, j});
                while (que.size()) {
                    auto front = que.front();
                    que.pop();
                    int x = front.first;
                    int y = front.second;
                    if (st[x][y] == true) continue;
                    st[x][y] = true;
                    if (x + 1 < n && grid[x + 1][y] == '1') que.push({x + 1, y});
                    if (y + 1 < m && grid[x][y + 1] == '1') que.push({x, y + 1});
                    if (x - 1 >= 0 && grid[x - 1][y] == '1') que.push({x - 1, y});
                    if (y - 1 >= 0 && grid[x][y - 1] == '1') que.push({x, y - 1});
                }
            }
        }
        return res;
    }
};
// @lc code=end
