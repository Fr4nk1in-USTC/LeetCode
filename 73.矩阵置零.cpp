/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool c0 = false, r0 = false;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                c0 = true;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (matrix[0][i] == 0)
            {
                r0 = true;
                break;
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
            }
        }
        if (r0)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[0][i] = 0;
            }
        }
        if (c0)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
// @lc code=end

