#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        int left = l;

        if (nums[l] != target) return {-1, -1};
        l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }

        int right = r;
        return {left, right};
    }
};
// @lc code=end
