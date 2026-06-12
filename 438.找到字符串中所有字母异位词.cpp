#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> umap;
        vector<int> res;

        for (auto c : p) umap[c]++;
        int size = umap.size();
        for (int i = 0, j = 0, satify = 0; j < s.size(); j++) {
            if (--umap[s[j]] == 0) satify++;
            if (j - i >= p.size()) {
                if (umap[s[i++]]++ == 0) satify--;
            }
            if (satify == size) res.push_back(i);
        }
        return res;
    }
};
// @lc code=end
