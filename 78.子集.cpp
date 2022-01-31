/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = 1 << nums.size(), m;
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i)
        {
            vector<int> ele;
            int idx = 0;
            for (m = i; m > 0; m >>= 1, idx++)
            {
                if (m & 1) ele.push_back(nums[idx]);
            }
            ans.push_back(ele);
        }
        return ans;
    }
};
// @lc code=end

