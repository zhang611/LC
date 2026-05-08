#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        pair<int, int> res(INT_MAX, INT_MAX);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1, k = nums.size() - 1; j < k; j++) {
                while (k - 1 > j && nums[i] + nums[j] + nums[k - 1] >= target)
                    k--;

                int s = nums[i] + nums[j] + nums[k];
                res = min(res, {abs(target - s), s});

                if (k - 1 > j) {
                    s = nums[i] + nums[j] + nums[k - 1];
                    res = min(res, {abs(target - s), s});
                }
            }
        }
        return res.second;
    }
};
// @lc code=end

// class Solution {
//    public:
//     int threeSumClosest(vector<int>& nums, int target) {
//         pair<int, int> res(INT_MAX, INT_MAX);
//         sort(nums.begin(), nums.end());

//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = i + 1, k = nums.size() - 1; j < k; j++) {
//                 while (k - 1 > j && nums[i] + nums[j] + nums[k - 1] >=
//                 target)
//                     k--;
//                 int s = nums[i] + nums[j] + nums[k];
//                 res = min(res, {abs(s - target), s});
//                 if (k - 1 > j) {
//                     s = nums[i] + nums[j] + nums[k - 1];
//                     res = min(res, {target - s, s});
//                 }
//             }
//         }
//         return res.second;
//     }
// };