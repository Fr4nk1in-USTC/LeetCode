/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include <vector>
#include <algorithm>
using std::min;
using std::vector;
// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount ; i++)
        {
            for (int coin : coins)
            {
                if (coin <= i)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};
// @lc code=end

