#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> deq;
        for (int i = 0; i < nums.size(); i++) {
            if (deq.size() && i - deq.front() >= k) deq.pop_front();
            while (deq.size() && nums[deq.back()] <= nums[i]) deq.pop_back();
            deq.push_back(i);
            if (i >= k - 1) res.push_back(nums[deq.front()]);
        }
        return res;
    }
};
// @lc code=end
