/*
 * @lc app=leetcode.cn id=1401 lang=cpp
 *
 * [1401] 圆和矩形是否有重叠
 */
#include <algorithm>
using std::max;
// @lc code=start
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int dx = max(x1 - xCenter, max(xCenter - x2, 0));
        int dy = max(y1 - yCenter, max(yCenter - y2, 0));
        return dx * dx + dy * dy <= radius * radius;
    }
};
// @lc code=end

