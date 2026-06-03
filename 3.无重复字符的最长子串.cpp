#include "leetcode_local.hpp"
using namespace std;

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int hash[128] = {0};
        int slow = 0;
        for (int i = 0; i < s.size(); i++) {
            hash[s[i]]++;
            while (hash[s[i]] >= 2) hash[s[slow++]]--;
            res = max(res, i - slow + 1);
        }
        return res;
    }
};
// @lc code=end
