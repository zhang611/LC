#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool flag = true;
        if (dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0) flag = false;
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long res = 0;
        vector<long long> exp;
        for (long long i = b; i <= a; i += i) exp.push_back(i);

        for (long long i = exp.size() - 1; i >= 0; i--) {
            if (a - exp[i] >= 0) {
                a -= exp[i];
                res += 1ll << i;
            }
        }

        if (flag == false) res = -res;
        if (res > INT_MAX || res < INT_MIN) return INT_MAX;
        return res;
    }
};
// @lc code=end
