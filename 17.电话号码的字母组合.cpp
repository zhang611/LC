#include <vector>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:

    string s[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string path;


    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return res;
        dfs(digits, 0);
        return res;
    }

    void dfs(string digits, int st) {
        if (st == digits.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < s[digits[st] - '0'].size(); i++) {
            char x = (char)(s[digits[st] - '0'][i]);
            path += x;
            dfs(digits, st + 1);
            path.pop_back();
        }
    }


};
// @lc code=end



// class Solution {
// public:
//     string s[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//     vector<string> res;
//     string path;
//     vector<string> letterCombinations(string digits) {
//         if (digits.size() == 0) return res;
//         dfs(digits, 0);
//         return res;
//     }

//     void dfs(string digits, int st) {
//         if (path.size() == digits.size()) {
//             res.push_back(path);
//             return;
//         }

//         for (auto c : s[digits[st] - '0']) {
//             path += c;
//             dfs(digits, st + 1);
//             path.pop_back();
//         }
//     }
// };