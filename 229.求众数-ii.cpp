/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */
#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int ele0 = 0, ele1 = 0;
        int vote0 = 0, vote1 = 0;
        for (int num : nums)
        {
            if (vote0 > 0 && num == ele0) vote0++;
            else if (vote1 > 0 && num == ele1) vote1++;
            else if (vote0 == 0)
            {
                ele0 = num;
                vote0++;
            }
            else if (vote1 == 0)
            {
                ele1 = num;
                vote1++;
            }
            else
            {
                vote0--;
                vote1--;
            }
        }
        int n = nums.size() / 3;
        int cnt0 = 0, cnt1 = 0;
        for (int num : nums)
        {
            if (vote0 > 0 && num == ele0) cnt0++;
            if (vote1 > 0 && num == ele1) cnt1++;
        }
        if (vote0 > 0 && cnt0 > n) ans.push_back(ele0);
        if (vote1 > 0 && cnt1 > n) ans.push_back(ele1);
        return ans;
    }
};
// @lc code=end

