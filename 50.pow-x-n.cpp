/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n < 0)
        {
            if (n == -2147483648) return 1.0 / x * myPow(1.0 /x, 2147483647);
            else return myPow(1.0 / x, -n);
        }
        double p = myPow(x, n/2);
        if (n & 1)
        {
            return x * p * p;
        }
        return p * p;
    }
};
// @lc code=end

