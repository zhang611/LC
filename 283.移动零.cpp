#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) nums[slow++] = nums[i];
        }
        for (int i = slow; i < nums.size(); i++) nums[i] = 0;
    }
};
// @lc code=end
