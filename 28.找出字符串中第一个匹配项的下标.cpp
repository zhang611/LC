#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        haystack = " " + haystack;
        needle = " " + needle;
        int ne[100010] = {0};

        for (int i = 2, j = 0; i <= m; i++) {
            while (j && needle[i] != needle[j + 1]) j = ne[j];
            if (needle[i] == needle[j + 1]) j++;
            ne[i] = j;
        }

        for (int i = 1, j = 0; i <= n; i++) {
            while (j && haystack[i] != needle[j + 1]) j = ne[j];
            if (haystack[i] == needle[j + 1]) j++;
            if (j == m) return i - j;
        }
        return -1;
    }
};
// @lc code=end

// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int n = haystack.size(), m = needle.size();
//         haystack = " " + haystack;
//         needle = " " + needle;

//         int ne[100010] = {0};
//         for (int i = 2, j = 0; i <= m; i++) {
//             while (j && needle[i] != needle[j + 1])
//                 j = ne[j];
//             if (needle[i] == needle[j + 1]) j++;
//             ne[i] = j;
//         }

//         for (int i = 1, j = 0; i <= n; i++) {
//             while (j && haystack[i] != needle[j + 1])
//                 j = ne[j];
//             if (haystack[i] == needle[j + 1]) j++;
//             if (j == m) return i - j;
//         }

//         return -1;
//     }
// };