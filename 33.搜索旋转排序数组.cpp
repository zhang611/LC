#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }

        int k = l;
        l = 0, r = k;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[l] == target) return l;

        l = k + 1, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[r] == target) return l;
        return -1;
    }
};
// @lc code=end

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;  // 这里为什么 +1
            if (nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }
        int k = l;
        cout << k << endl;

        l = 0, r = k;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[l] == target) return l;

        l = k + 1, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[r] == target) return l;  // 这里为什么是 r
        return -1;
    }
};