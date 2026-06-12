#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> uset;
        for (auto num : nums) uset.insert(num);

        int res = 1;
        for (auto num : uset) {
            if (uset.find(num - 1) != uset.end()) continue;

            int curLen = 1;
            while (uset.find(num + curLen) != uset.end()) curLen++;
            res = max(res, curLen);
        }
        return res;
    }
};
// @lc code=end
