#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                for (int l = j + 1; l < nums.size(); l++)
                {
                    if (l > j + 1 && nums[l] == nums[l - 1])
                        continue;
                    int r = nums.size() - 1;
                    while (l < r - 1 && (long)nums[i] + nums[j] + nums[l] + nums[r - 1] >= target)
                        r--;
                    if (l < r && (long)nums[i] + nums[j] + nums[l] + nums[r] == target)
                    {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

// -2 -1 0 0 1 2

// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         sort(nums.begin(), nums.end());

//         vector<vector<int>> res;
//         for (int i = 0; i < nums.size(); i++) {
//             if (i && nums[i] == nums[i-1]) continue;
//             for (int j = i + 1; j < nums.size(); j++) {
//                 if (j > i + 1 && nums[j] == nums[j - 1]) continue;
//                 for (int l = j + 1; l < nums.size(); l++) {
//                     if (l > j + 1 && nums[l] == nums[l - 1]) continue;
//                     int r = nums.size() - 1;
//                     while(l < r - 1 && (long)nums[i] + nums[j] + nums[l] + nums[r - 1] >= target) r--;
//                     if (l < r && (long)nums[i] + nums[j] + nums[l] + nums[r] == target) {
//                         res.push_back({nums[i], nums[j], nums[l], nums[r]});
//                     }
//                 }
//             }
//         }
//         return res;

//     }
// };