#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> que;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) que.push({i, j});
            }
        }

        if (que.size() == 0 && hasFresh(grid)) return -1;
        if (que.size() == 0 && !hasFresh(grid)) return 0;

        int largestNum = n * m;
        int res = 0;
        while (largestNum--) {
            if (!hasFresh(grid)) return res;
            cout << que.size() << endl;

            int size = que.size();
            int size2 = que.size();
            while (size2--) {
                auto t = que.front();
                cout << t.first << " " << t.second << endl;
                que.pop();
                que.push(t);
            }
            cout << endl;

            res++;

            while (size--) {
                auto front = que.front();
                que.pop();
                int x = front.first;
                int y = front.second;

                if (x + 1 < n && grid[x + 1][y] == 1) grid[x + 1][y] = 2, que.push({x + 1, y});
                if (y + 1 < m && grid[x][y + 1] == 1) grid[x][y + 1] = 2, que.push({x, y + 1});
                if (x - 1 >= 0 && grid[x - 1][y] == 1) grid[x - 1][y] = 2, que.push({x - 1, y});
                if (y - 1 >= 0 && grid[x][y - 1] == 1) grid[x][y - 1] = 2, que.push({x, y - 1});
            }
        }

        return -1;
    }

    bool hasFresh(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return true;
            }
        }
        return false;
    }
};
// @lc code=end
