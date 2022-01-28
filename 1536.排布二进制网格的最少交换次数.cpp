/*
 * @lc app=leetcode.cn id=1536 lang=cpp
 *
 * [1536] 排布二进制网格的最少交换次数
 */
#include <vector>
#include <algorithm>
using std::swap;
using std::vector;
// @lc code=start
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> pos(n, -1);
        for (int i = 0; i < n; ++i)
        {
            for (int j = n - 1; j > -1; --j)
            {
                if (grid[i][j] == 1)
                {
                    pos[i] = j;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int flag = -1;
            for (int j = i; j < n; ++j)
            {
                if (pos[j] <= i)
                {
                    ans += j - i;
                    flag = j;
                    break;
                }
            }
            if (~flag)
                for (int j = flag; j > i; --j)
                    swap(pos[j], pos[j - 1]);
            else return -1;
        }
        return ans;
    }
};
// @lc code=end

