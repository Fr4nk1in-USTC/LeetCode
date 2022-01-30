/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        int high = m - 1, low = 0;
        int mid = 0;
        while (high >= low)
        {
            mid = (high + low) / 2;
            if (matrix[mid][0] == target) return true;
            if (matrix[mid][0] > target) high = mid - 1;
            else if (matrix[mid][n - 1] < target) low = mid + 1;
            else break;
        }
        int k = mid;
        high = n - 1;
        low = 0;
        while (high >= low)
        {
            mid = (high + low) / 2;
            if (matrix[k][mid] == target) return true;
            if (matrix[k][mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};
// @lc code=end

