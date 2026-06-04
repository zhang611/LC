#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int start = -1;
        int len = INT_MAX;
        unordered_map<char, int> cnt;
        for (auto c : t) cnt[c]++;
        int tot = cnt.size();
        for (int i = 0, j = 0, satify = 0; i < s.size(); i++) {
            if (--cnt[s[i]] == 0) satify++;

            while (satify == tot) {
                if (i - j + 1 < len) {
                    start = j;
                    len = i - j + 1;
                }
                if (cnt[s[j++]]++ == 0) satify--;
            }
        }

        return start == -1 ? "" : s.substr(start, len);
    }
};
// @lc code=end
