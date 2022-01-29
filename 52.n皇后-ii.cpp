/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        return solve(n, 0, 0, 0, 0);
    }
    int solve(int n, int r, int c, int d1, int d2)
    {
        if (n == r) return 1;
        int cnt = 0;
        int avaPos = ((1 << n) - 1) & (~(c | d1 | d2));
        while (avaPos)
        {
            int pos = (-avaPos) & avaPos;
            avaPos &= (avaPos - 1);
            cnt += solve(n, r + 1, c | pos, (d1 | pos) << 1, (d2 | pos) >> 1);
        }
        return cnt;
    }
};
// @lc code=end

