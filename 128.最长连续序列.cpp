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
        int res = 1;
        unordered_set<int> uset;

        for (int i = 0; i < nums.size(); i++) uset.insert(nums[i]);

        for (auto num : uset) {
            if (uset.find(num - 1) == uset.end()) {
                int curLength = 1;
                while (uset.find(num + curLength) != uset.end()) {
                    curLength++;
                    res = max(res, curLength);
                }
            }
        }
        return res;
    }
};
// @lc code=end
