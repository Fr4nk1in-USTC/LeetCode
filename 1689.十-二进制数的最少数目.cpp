/*
 * @lc app=leetcode.cn id=1689 lang=cpp
 *
 * [1689] 十-二进制数的最少数目
 */
#include <string>
#include <algorithm>
using std::string;
using std::max;
// @lc code=start
class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (auto& c : n)
            ans = max(ans, c - '0');
        return ans;
    }
};
// @lc code=end

