#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int t = x;
        long long res = 0;
        while(x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res == t;
    }
};
// @lc code=end
