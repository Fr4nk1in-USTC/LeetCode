/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */
#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        vector<bool> isPrime(n, 1);
        int cnt = n >> 1;
        for (int i = 3; i * i < n; i += 2)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j < n; j += i << 1)
                {
                    if (isPrime[j])
                    {
                        cnt --;
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

