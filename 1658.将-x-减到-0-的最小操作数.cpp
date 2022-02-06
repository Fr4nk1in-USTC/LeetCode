/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */
#include <vector>
#include <algorithm>
using std::max;
using std::vector;

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size();
        for (auto& num : nums) sum += num;
        int target = sum - x;
        if (target < 0) return -1;
        sum = 0;
        int l = 0, r = 0;
        int cnt = -1;
        while (r < n)
        {
            sum += nums[r++];
            while (sum > target && l < r) sum -= nums[l++];
            if (sum == target) cnt = max(cnt, r - l);
        }
        return cnt == -1 ? -1 : n - cnt;
    }
};
// @lc code=end

