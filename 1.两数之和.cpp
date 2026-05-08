#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            if (umap.count(target - nums[i])) {
                return {i, umap[target - nums[i]]};
            }
            umap[nums[i]] = i;
        }
        return {-1, -1};
    }
};
// @lc code=end
