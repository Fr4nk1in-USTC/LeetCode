/*
 * @lc app=leetcode.cn id=1864 lang=cpp
 *
 * [1864] 构成交替字符串需要的最小交换次数
 */
#include <string>
#include <algorithm>
using std::min;
using std::string;
// @lc code=start
class Solution {
public:
    int minSwaps(string s) {
        int num[2] = {0, 0}, odd1 = 0, n = s.size();
        for (int i = 0; i < n; i++)
        {
            num[s[i] - '0'] ++;
            odd1 += ((i & 1) && (s[i] - '0'));
        }
        if (num[0] - num[1] > 1 || num[0] - num[1] < -1)
        {
            return -1;
        }
        if (!(n & 1)) return min(odd1, (n >> 1) - odd1);
        if (num[0] > num[1]) return (n >> 1) - odd1;
        return odd1;
    }
};
// @lc code=end

