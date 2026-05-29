#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string pre = countAndSay(n - 1);

        string res = "";
        for (int i = 0; i < pre.size(); i++) {
            int count = 1;
            while (i + 1 < pre.size() && pre[i + 1] == pre[i]) i++, count++;
            res += to_string(count);
            res += pre[i];
        }
        return res;
    }
};
// @lc code=end
