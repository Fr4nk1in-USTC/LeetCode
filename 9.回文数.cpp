/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include <stack>
#include <queue>
// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        if (x % 10 == 0) return false;
        int r = 0;
        while (x > r)
        {
            r = x % 10 + 10 * r;
            x /= 10;
        }
        return r == x || r / 10 == x;
    }
};
// @lc code=end

