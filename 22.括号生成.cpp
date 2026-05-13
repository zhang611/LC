#include <string>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return res;
    }

    void dfs(int n, int lc, int rc, string path) {
        if (lc == n && rc == n)
            res.push_back(path);
        else {
            if (lc < n)
                dfs(n, lc + 1, rc, path + "(");
            if (rc < n && rc < lc)
                dfs(n, lc, rc + 1, path + ")");
        }
    }
};
// @lc code=end

// class Solution {
// public:

//     vector<string> res;

//     void dfs(int n, int lc, int rc, string path) {
//         if (lc == n && rc == n) res.push_back(path);
//         else {
//             if (lc < n) dfs(n, lc+1, rc, path+'(');
//             if (rc < n && lc > rc) dfs(n, lc, rc+1, path+')');
//         }
//     }

//     vector<string> generateParenthesis(int n) {
//         dfs(n, 0, 0, "");
//         return res;
//     }
// };