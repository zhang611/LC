#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 1 && nums[0] != k) return 0;
        int res = 0;
        int sum = 0;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k) res++;
            while (sum > k) {
                sum -= nums[j++];
                if (sum == k) res++;
            }
        }
        return res;
    }
};
// @lc code=end
