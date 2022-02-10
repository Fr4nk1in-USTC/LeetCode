/*
 * @lc app=leetcode.cn id=793 lang=cpp
 *
 * [793] 阶乘函数后 K 个零
 */

// @lc code=start
class Solution {
public:
    int preimageSizeFZF(int k) {
        long long low = 0, high = 10L * k + 1;
        long long mid = 0, z = 0;
        while (low < high)
        {
            mid = (low + high) / 2;
            if (k == (z = zeta(mid))) return 5;
            if (z > k) high = mid - 1;
            else low = mid + 1;
        }
        return 0;
    }
    long long zeta(long long k)
    {
        if (k < 5) return 0;
        return k / 5 + zeta(k / 5);
    }
};
// @lc code=end

