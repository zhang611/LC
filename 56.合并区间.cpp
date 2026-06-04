#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    bool static cmp(const vector<int> a, const vector<int> b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), cmp);
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (res.back().back() >= intervals[i][1]) continue;
            if (res.back().back() >= intervals[i][0]) {
                res.back().back() = intervals[i][1];
            } else res.push_back(intervals[i]);
        }
        return res;
    }
};
// @lc code=end
