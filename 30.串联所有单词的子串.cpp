#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.size() == 0) return res;
        if (words[0].size() == 0) return res;
        int n = s.size(), m = words.size(), w = words[0].size();

        unordered_map<string, int> all;
        for (auto i : words) all[i]++;

        for (int i = 0; i < w; i++) {
            int cnt = 0;
            unordered_map<string, int> wd;
            for (int j = i; j < n; j += w) {
                if (j >= i + m * w) {
                    string word = s.substr(j - m * w, w);
                    wd[word]--;
                    if (wd[word] < all[word]) cnt--;
                }
                string word = s.substr(j, w);
                wd[word]++;
                if (wd[word] <= all[word]) cnt++;
                if (cnt == m) res.push_back(j - (m - 1) * w);
            }
        }
        return res;
    }
};
// @lc code=end
