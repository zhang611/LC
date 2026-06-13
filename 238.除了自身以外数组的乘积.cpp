#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除了自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n + 1, 1);
        for (int i = 0; i < nums.size(); i++) p[i + 1] = p[i] * nums[i];

        for (int i = n - 1, s = 1; i >= 0; i--) {
            p[i] *= s;
            s *= nums[i];
        }
        p.pop_back();
        return p;
    }
};
// @lc code=end
