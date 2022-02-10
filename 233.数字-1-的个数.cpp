/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */
#include <algorithm>
using std::min;
using std::max;
// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {
        long long ans = 0;
        long long base = 1;
        while (n >= base)
        {
            ans += n / (base * 10) * base;
            ans += min(max((n % (base * 10) - base + 1), 0LL), base);
            base *= 10;
        }
        return ans;
    }
};
// @lc code=end

