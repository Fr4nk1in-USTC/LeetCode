/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */
#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int neighbor = 0;
                for (int ioff = ((i == 0) ? 0 : -1); ioff < ((i == m - 1) ? 1 : 2); ioff++)
                {
                    for (int joff = ((j == 0) ? 0 : -1); joff < ((j == n - 1) ? 1 : 2); joff++)
                    {
                        if (ioff == 0 && joff == 0) continue;
                        neighbor += (board[i + ioff][j + joff] & 1);
                    }
                }
                if ((board[i][j] & 1) == 1 && (neighbor == 2 || neighbor == 3)) board[i][j] += 2;
                else if ((board[i][j] & 1) == 0 && neighbor == 3) board[i][j] += 2;
                else board[i][j] &= 1;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                board[i][j] >>= 1;
        }
    }
};
// @lc code=end

