#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
  bool isValid(string s) {
    vector<char> res;
    if (s == "")
      return true;
    for (int i = 0; i < s.size(); i++) {
      if (res.size() == 0 && (s[i] == ')' || s[i] == ']' || s[i] == '}'))
        return false;
      if (s[i] == ')' && res.back() == '(')
        res.pop_back();

      else if (s[i] == ']' && res.back() == '[')
        res.pop_back();

      else if (s[i] == '}' && res.back() == '{')
        res.pop_back();

      else if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        res.push_back(s[i]);
      else
        return false;
    }

    if (res.size() > 0)
      return false;
    return true;
  }
};
// @lc code=end
