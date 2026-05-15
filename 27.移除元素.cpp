#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) continue;
            nums[index++] = nums[i];
        }
        return index;
    }
};
// @lc code=end
