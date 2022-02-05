/*
 * @lc app=leetcode.cn id=1414 lang=cpp
 *
 * [1414] 和为 K 的最少斐波那契数字数目
 */
#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib(2, 1);
        int n = 2;
        while (fib[n - 1] + fib[n - 2] <= k)
        {
            fib.push_back(fib[n - 1] + fib[n - 2]);
            n++;
        }
        int cnt = 0;
        for (int i = n - 1; i >= 0 && k > 0; i--)
        {
            if (k >= fib[i])
            {
                k -= fib[i];
                cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end

