#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        int maxSize = 0;
        for (int k = 0; k < strs.size(); k++) {
            if (strs[k] == "") return "";
            maxSize = max(maxSize, (int)strs[k].size());
        }

        string res = "";

        for (int i = 0; i < maxSize; i++) {
            char x = strs[0][i];
            for (int j = 0; j < strs.size(); j++) {
                if (i > strs[j].size()) return res;
                if (strs[j][i] != x) return res;
            }
            res += x;
        }

        return res;
    }
};
// @lc code=end



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int hash[26] = {0};
        string res = "";
        for (int i = 0; i < strs[0].size(); i++) {
            hash[strs[0][i] - 'a']++;
            for (int j = 1; j < strs.size(); j++) {
                // cout << strs[j][i] << endl;
                if (i >= strs[j].size()) return res;
                if (hash[strs[j][i] - 'a'] < 1) return res;
                
            }
            res += strs[0][i];
            hash[strs[0][i] - 'a']--;
        }
        return res;
    }
};