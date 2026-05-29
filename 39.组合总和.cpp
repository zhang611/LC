#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }

    void dfs(vector<int>& candidates, int target, int st) {
        if (sum == target) res.push_back(path);
        if (sum >= target) return;

        for (int i = st; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            dfs(candidates, target, i);
            path.pop_back();
            sum -= candidates[i];
        }
    }
};
// @lc code=end
