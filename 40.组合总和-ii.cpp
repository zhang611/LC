#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }

    void dfs(vector<int>& candicate, int target, int st) {
        if (sum == target) res.push_back(path);
        if (sum >= target) return;

        for (int i = st; i < candicate.size(); i++) {
            if (i > st && candicate[i] == candicate[i - 1]) continue;
            sum += candicate[i];
            path.push_back(candicate[i]);
            dfs(candicate, target, i + 1);
            path.pop_back();
            sum -= candicate[i];
        }
    }
};
// @lc code=end
