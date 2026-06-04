#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> umap;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (umap.find(s) != umap.end()) umap[s].push_back(strs[i]);
            else umap[s] = {strs[i]};
        }

        for (auto it = umap.begin(); it != umap.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};
// @lc code=end
