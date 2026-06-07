#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0, r = n - 1;
        while(l < r) {
            int mid = (l + r + 1) / 2;
            if (matrix[mid][0] <= target) l = mid;
            else r = mid - 1;
        }
        int endX = l;

        l = 0, r = m - 1;
        while(l < r) {
            int mid = (l + r + 1) / 2;
            if (matrix[0][mid] <= target) l = mid;
            else r = mid - 1;
        }
        int endY = l;

        l = 0, r = endX;
        while(l < r) {
            int mid = (l + r) / 2;
            if (matrix[mid][endY] >= target) r = mid;
            else l = mid + 1;
        }
        int startX = l;

        l = 0, r = endY;
        while(l < r) {
            int mid = (l + r) / 2;
            if (matrix[endX][mid] >= target) r = mid;
            else l = mid + 1;
        }
        int startY = l;

        cout << startX << endl;
        cout << endX << endl;
        cout << startY << endl;
        cout << endY << endl;

        for (int i = startX; i <= endX; i++) {
            for (int j = startY; j <= endY; j++) {
                if (matrix[i][j] == target) return true;
            }
        }
        return false;











        // stack<pair<int, int>> st;
        // st.push(pair(0, 0));
        // while (st.size()) {
        //     pair<int, int> top = st.top();
        //     int topi = top.first;
        //     int topj = top.second;
        //     if (matrix[topi][topj] == target) return true;
        //     st.pop();
        //     if (topi < n - 1 && matrix[topi + 1][topj] <= target) st.push(pair(topi + 1, topj));
        //     if (topj < m - 1 && matrix[topi][topj + 1] <= target) st.push(pair(topi, topj + 1));
        // }
        // return false;
    }
};
// @lc code=end

// 1. 感觉可以用栈做,太慢了
// 2. 四次二分,先找左右元素都小于target的左上角矩阵
// 再找所有元素都大于target的右下角矩阵