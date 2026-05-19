#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = nums.size() - 1;
        while (k > 0 && nums[k] <= nums[k - 1]) k--;
        if (k == 0)
            reverse(nums.begin(), nums.end());
        else {
            int t = k;
            while (t < nums.size() && nums[t] > nums[k - 1]) t++;
            swap(nums[k - 1], nums[t - 1]);
            reverse(nums.begin() + k, nums.end());
        }
    }
};
// @lc code=end

// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int k = nums.size()-1;
//         while(k > 0 && nums[k] <= nums[k-1]) k--;
//         if (k == 0) reverse(nums.begin(), nums.end());
//         else {
//             int t = k;
//             while(t < nums.size() && nums[t] > nums[k-1]) t++;
//             swap(nums[k-1], nums[t-1]);
//             reverse(nums.begin() + k, nums.end());
//         }
//     }
// };

// 1 2 3 4 5
// 1 3 2 5 4

// k 3
// t 4
// 1 3 4 5 2
// 1 3 4 2 5