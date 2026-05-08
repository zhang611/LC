#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;

        if (total % 2) {
            return find(nums1, nums2, (total - 1) / 2);
        } else {
            return (find(nums1, nums2, (total / 2) - 1) +
                    find(nums1, nums2, total / 2)) /
                   2.0;
        }
    }

    int find(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        int index1 = 0, index2 = 0;

        while (index1 < n && index2 < m && k > 0) {
            int endIndex1 = min(index1 + (k - 1) / 2, n - 1);
            int endIndex2 = min(index2 + (k - 1) / 2, m - 1);
            int num1 = nums1[endIndex1];
            int num2 = nums2[endIndex2];

            if (num1 <= num2) {
                k -= (endIndex1 - index1 + 1);
                index1 = endIndex1 + 1;
            } else {
                k -= (endIndex2 - index2 + 1);
                index2 = endIndex2 + 1;
            }
        }

        if (index1 == n) return nums2[index2 + k];
        if (index2 == m) return nums1[index1 + k];
        return min(nums1[index1], nums2[index2]);
    }
};
// @lc code=end
