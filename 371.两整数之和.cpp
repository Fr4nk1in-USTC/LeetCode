/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        int n = sizeof(int) * 8;
        unsigned int c = 0, g = 0, p = 0, s = 0;
        unsigned int mask = 1;
        for (int i = 0; i < n; i++)
        {
            g = (a & mask) & (b & mask);
            p = (a & mask) ^ (b & mask);
            s |= p ^ c;
            c = g | (p & c);
            c <<= 1;
            mask <<= 1;
        }
        return *(int *)(&s);
    }
};
// @lc code=end

