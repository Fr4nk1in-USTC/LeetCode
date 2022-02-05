/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */
#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0, max = 0;
        for (int i = 0; i < k; i++) sum += cardPoints[i];
        max = sum;
        for (int i = 0; i < k; i++)
        {
            sum += cardPoints[n - 1 - i] - cardPoints[k - 1 - i];
            if (sum > max) max = sum;
        }
        return max;
    }
};
// @lc code=end

