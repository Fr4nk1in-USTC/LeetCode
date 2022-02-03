/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */

// @lc code=start
class Solution {
public:
    int integerReplacement(int n) {
        int cnt = 0;
        while (n != 1)
        {
            if (n == 3)
            {
                cnt += 2;
                break;
            }
            else if (n & 1)
            {
                n >>= 1;
                cnt += 2;
                if (n & 1) n++;
            }
            else
            {
                n >>= 1;
                cnt += 1;
            }
        }
        return cnt;
    }
};
// @lc code=end

