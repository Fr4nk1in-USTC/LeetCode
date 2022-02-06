/*
 * @lc app=leetcode.cn id=1561 lang=cpp
 *
 * [1561] 你可以获得的最大硬币数目
 */
#include <vector>
#include <algorithm>
using std::vector;
using std::sort;
// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int m = n / 3;
        int ans = 0;
        for (int i = 1; i <= m; i++)
            ans += piles[n - (i << 1)];
        return ans;
    }
};
// @lc code=end

