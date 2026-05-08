#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
   public:
    bool isMatch(string s, string p) {
        if (p.size() <= 0) return s.size() <= 0;
        bool match = (s.size() > 0 && (s[0] == p[0] || p[0] == '.'));

        if (p.size() > 1 && p[1] == '*') {
            // cout << s << endl << p.substr(2) << endl;
            return isMatch(s, p.substr(2)) ||
                   (match && isMatch(s.substr(1), p));
        } else {
            return match && isMatch(s.substr(1), p.substr(1));
        }
    }
};
// @lc code=end


class Solution {
public:
    bool isMatch(string s, string p) {
        // 本题添加了新数据：s = "abc", p = "a***abc"
        // 之前的做法未考虑'*'前也是'*'的情况，所以初始时只要把p中连续的'*'改成一个'*'即可
        string t;
        for (auto c: p)
            if (c != '*' || t.back() != '*')
                t += c;
        p = t;

        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        f[0][0] = true;
        for (int i = 0; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ ) {
                if (j + 1 <= m && p[j + 1] == '*') continue;
                if (i && p[j] != '*') {
                    f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                } else if (p[j] == '*') {
                    f[i][j] = f[i][j - 2] || i && f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.');
                }
            }

        return f[n][m];
    }
};
