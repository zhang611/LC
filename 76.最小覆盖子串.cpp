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
        unordered_map<int, int> cnt;
        int start = -1;
        int len = INT_MAX;
        for (auto c : t) cnt[c]++;
        int size = cnt.size();

        for (int i = 0, j = 0, satify = 0; j < s.size(); j++) {
            if (--cnt[s[j]] == 0) satify++;

            while (satify == size) {
                if (j - i + 1 < len) {
                    start = i;
                    len = j - i + 1;
                }

                if (cnt[s[i++]]++ == 0) satify--;
            }
        }

        if (start == -1) return "";
        return s.substr(start, len);
    }
};
// @lc code=end
