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
        vector<int> res;
        unordered_map<char, int> cnt;
        for (auto c : p) cnt[c]++;
        int tot = cnt.size();

        for (int i = 0, j = 0, satify = 0; i < s.size(); i++) {
            if (--cnt[s[i]] == 0) satify++;
            if (i - j >= p.size()) {
                if (cnt[s[j++]]++ == 0) satify--;
            }
            if (satify == tot) res.push_back(j);
        }
        return res;
    }
};
// @lc code=end
