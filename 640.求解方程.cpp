/*
 * @lc app=leetcode.cn id=640 lang=cpp
 *
 * [640] 求解方程
 */
#include <string>
using std::string;
#include <algorithm>
using std::to_string;
// @lc code=start
class Solution {
public:
    string solveEquation(string equation) {
        int lx = 0, rx = 0, lnum = 0, rnum = 0, num = 0;
        bool left = true, flag = false;
        int sign = 1;
        int n = equation.size();
        for (int i = 0; i < n; i++)
        {
            switch (equation[i])
            {
                case '+':
                    if (left) lnum += num * sign;
                    else rnum += num * sign;
                    sign = 1;
                    num = 0;
                    flag = false;
                    break;
                
                case '-':
                    if (left) lnum += num * sign;
                    else rnum += num * sign;
                    sign = -1;
                    num = 0;
                    flag = false;
                    break;

                case 'x':
                    if (!flag) num = 1;
                    if (left) lx += num * sign;
                    else rx += num * sign;
                    num = 0;
                    flag = false;
                    break;

                case '=':
                    lnum += num * sign;
                    sign = 1;
                    left = false;
                    num = 0;
                    flag = false;
                    break;

                default:
                    flag = true;
                    num *= 10;
                    num += equation[i] - '0';
                    break;
            }
        }
        if (num != 0) rnum += num * sign;
        if (lx == rx && lnum == rnum) return "Infinite solutions";
        if (lx == rx) return "No solution";
        return "x=" + to_string((rnum - lnum)/(lx - rx));
    }
};
// @lc code=end

