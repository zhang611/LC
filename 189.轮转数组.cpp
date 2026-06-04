#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int n = nums.size() - k;
        for (int l = 0, r = n - 1; l < r; l++, r--) swap(nums[l], nums[r]);
        for (int l = n, r = nums.size() - 1; l < r; l++, r--) swap(nums[l], nums[r]);
        for (int l = 0, r = nums.size() - 1; l < r; l++, r--) swap(nums[l], nums[r]);
    }
};
// @lc code=end
