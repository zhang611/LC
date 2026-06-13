#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur = max(nums[i], cur + nums[i]);
            sum = max(cur, sum);
        }
        return sum;
    }
};
// @lc code=end
