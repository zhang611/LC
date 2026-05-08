#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] > 0)
                    r--;
                else if (nums[i] + nums[l] + nums[r] < 0)
                    l++;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l + 1 < r && nums[l + 1] == nums[l]) l++;
                    while (r - 1 > l && nums[r - 1] == nums[r]) r--;
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
