/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 */
int rand7();
// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int fir, sec;
        while ((fir = rand7()) == 7);
        while ((sec = rand7()) > 5);
        return (fir & 1) ? 5 + sec : sec;
    }
};
// @lc code=end

