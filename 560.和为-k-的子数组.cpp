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
        unordered_map<int, int> umap;
        umap[0]++;

        int res = 0;
        vector<int> s(nums.size() + 1);
        s[0] = 0;
        for (int i = 0; i < nums.size(); i++) s[i + 1] = s[i] + nums[i];
        for (int i = 1; i <= nums.size(); i++) {
            res += umap[s[i] - k];
            umap[s[i]]++;
        }

        return res;
    }
};
// @lc code=end
