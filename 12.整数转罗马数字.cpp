#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
   public:
    string intToRoman(int num) {
        string qian[4] = {"", "M", "MM", "MMM"};
        string shi[10] = {"",  "X",  "XX",  "XXX",  "XL",
                          "L", "LX", "LXX", "LXXX", "XC"};
        string bai[10] = {"",  "C",  "CC",  "CCC",  "CD",
                          "D", "DC", "DCC", "DCCC", "CM"};
        string ge[10] = {"",  "I",  "II",  "III",  "IV",
                         "V", "VI", "VII", "VIII", "IX"};

        string num_str = to_string(num);
        string res = "";
        for (int i = 0; i < num_str.size(); i++) {
            if (num_str.size() - i == 4) res += qian[num_str[i] - '0'];
            if (num_str.size() - i == 3) res += bai[num_str[i] - '0'];
            if (num_str.size() - i == 2) res += shi[num_str[i] - '0'];
            if (num_str.size() - i == 1) res += ge[num_str[i] - '0'];
        }
        return res;
    }
};
// @lc code=end

// class Solution {
//    public:
//     string qian[10] = {"", "M", "MM", "MMM"};
//     string bai[10] = {"",  "C",  "CC",  "CCC",  "CD",
//                       "D", "DC", "DCC", "DCCC", "CM"};
//     string shi[10] = {"",  "X",  "XX",  "XXX",  "XL",
//                       "L", "LX", "LXX", "LXXX", "XC"};
//     string ge[10] = {"",  "I",  "II",  "III",  "IV",
//                      "V", "VI", "VII", "VIII", "IX"};

//     string intToRoman(int num) {
//         string str_num = to_string(num);
//         string res;
//         for (int i = 1; i <= str_num.size(); i++) {
//             if (str_num.size() - i == 3) {
//                 res += qian[str_num[i - 1] - '0'];
//             }
//             if (str_num.size() - i == 2) {
//                 res += bai[str_num[i - 1] - '0'];
//             }
//             if (str_num.size() - i == 1) {
//                 res += shi[str_num[i - 1] - '0'];
//             }
//             if (str_num.size() - i == 0) {
//                 res += ge[str_num[i - 1] - '0'];
//             }
//         }

//         return res;
//     }
// };