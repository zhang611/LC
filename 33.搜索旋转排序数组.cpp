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
            int mid = (l + r) >> 1;
            if (nums[mid] >= nums[0]) l = mid;
            else l = mid + 1;
        }

        int k = l;

        cout << k << endl;
        l = 0, r = k;
        while (l < r) {
            int mid = l + r >> 1;
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
        if (nums[r] == target) return l;

        return -1;
    }
};
// @lc code=end

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // if (nums.size() == 0) return -1;
        // if (nums.size() == 1) {
        //     if (nums[0] == target) return 0;
        //     return -1;
        // }

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
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
        if (nums[r] == target) return l;
        return -1;
    }
};