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
        int res = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = nums[i] + max(0, sum);
            res = max(res, sum);
        }
        return res;
    }
};
// @lc code=end


// 其实这个代码是简化后的dp