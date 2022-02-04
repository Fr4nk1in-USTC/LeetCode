/*
 * @lc app=leetcode.cn id=678 lang=cpp
 *
 * [678] 有效的括号字符串
 */
#include <string>
using std::string;
#include <algorithm>
using std::max;
// @lc code=start
class Solution {
public:
    bool checkValidString(string s) {
        int mincnt = 0, maxcnt = 0;
        for (char c : s)
        {
            switch (c)
            {
                case '(':
                    mincnt++;
                    maxcnt++;
                    break;

                case ')':
                    maxcnt--;
                    mincnt = max(mincnt - 1, 0);
                    if (maxcnt < 0) return false;
                    break;
                case '*':
                    mincnt = max(mincnt - 1, 0);
                    maxcnt++;
                    break;
            }
        }
        return mincnt == 0;
    }
};
// @lc code=end

