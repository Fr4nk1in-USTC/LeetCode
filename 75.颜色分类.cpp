/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include <vector>
#include <algorithm>
using std::swap;
using std::vector;
// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p2 = n - 1;
        for (int i = 0; i <= p2; i++)
        {
            while (i <= p2 && nums[i] == 2)
            {
                swap(nums[i], nums[p2]);
                --p2;
            }
            if (nums[i] == 0)
            {
                swap(nums[p0], nums[i]);
                ++p0;
            }
        }
    }
};
// @lc code=end

