#include "leetcode_local.hpp"
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); i++) {
            while (st.size() && height[st.top()] < height[i]) {
                int mid = st.top();
                st.pop();
                if (st.size()) {
                    int w = i - st.top() - 1;
                    int h = min(height[i], height[st.top()]) - height[mid];
                    res += w * h;
                }
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end
