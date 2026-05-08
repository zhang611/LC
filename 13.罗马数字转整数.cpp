#include <string>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
   public:
    int romanToInt(string s) {
        unordered_map<char, int> umap;
        umap['I'] = 1;
        umap['V'] = 5;
        umap['X'] = 10;
        umap['L'] = 50;
        umap['C'] = 100;
        umap['D'] = 500;
        umap['M'] = 1000;
        int res = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (umap[s[i + 1]] > umap[s[i]])
                res -= umap[s[i]];
            else
                res += umap[s[i]];
        }
        res += umap[s[s.size() - 1]];
        return res;
    }
};
// @lc code=end

// class Solution {
// public:
//     int romanToInt(string s) {
//         int res = 0;
//         unordered_map<char, int> nums;
//         nums['I'] = 1;
//         nums['V'] = 5;
//         nums['X'] = 10;
//         nums['L'] = 50;
//         nums['C'] = 100;
//         nums['D'] = 500;
//         nums['M'] = 1000;

//         for (int i = 0; i < s.size() - 1; i++) {
//             if (nums[s[i+1]] > nums[s[i]]) res -= nums[s[i]];
//             else res += nums[s[i]];
//         }
//         res += nums[s[s.size() - 1]];

//         return res;
//     }

// };