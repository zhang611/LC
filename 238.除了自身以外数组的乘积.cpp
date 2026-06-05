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
        vector<int> s1(n + 1);
        vector<int> s2(n + 1);
        s1[0] = 1, s2[n] = 1;

        for (int i = 1; i <= n; i++) s1[i] = s1[i - 1] * nums[i - 1];
        for (int i = n - 1; i >= 0; i--) s2[i] = s2[i + 1] * nums[i];

        vector<int> res;
        for (int i = 1; i <= n; i++) {
            res.push_back(s1[i - 1] * s2[i]);
        }
        return res;
    }
};
// @lc code=end
