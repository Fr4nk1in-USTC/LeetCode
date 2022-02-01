/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include <algorithm>
using std::swap;
// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) swap(m, n);
        long long ans = 1;
        for (int i = n, j = 1; j < m; i++, j++)
        {
            ans *= i;
            ans /= j;
        }
        return ans;
    }
};
// @lc code=end

