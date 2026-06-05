#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int res = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != i + 1 &&
                nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
                i--;
            }
        }

        while (res <= nums.size() && res == nums[res - 1]) res++;
        return res;
    }
};
// @lc code=end
