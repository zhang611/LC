#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
   public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            res = max(res, (r - l) * min(height[l], height[r]));
            if (height[l] <= height[r])
                l++;
            else
                r--;
        }
        return res;
    }
};
// @lc code=end
