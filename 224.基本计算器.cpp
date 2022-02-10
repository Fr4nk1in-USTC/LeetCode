/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */
#include <string>
#include <stack>
using std::string;
using std::stack;
// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<char> opers;
        stack<int> nums;
        int num = 0;
        int n = s.size();
        int temp = 0;
        while (temp < n && s[temp] == ' ') temp++;
        if (s[temp] == '+' || s[temp == '-']) nums.push(0);
        for (int i = 0; i < n; i++)
        {
            switch (s[i])
            {
                case ' ':
                    break;

                case '(':
                    opers.push(s[i]);
                    temp = i + 1;
                    while (temp < n && s[temp] == ' ') temp++;
                    if (s[temp] == '-' || s[temp] == '+') nums.push(0);
                    break;
                
                case ')':
                    num = 0;
                    while (opers.top() != '(')
                    {
                        int op1 = nums.top();
                        nums.pop();
                        char oper = opers.top();
                        opers.pop();
                        if (oper == '+') num += op1;
                        else num -= op1;
                    }
                    opers.pop();
                    num += nums.top();
                    nums.pop();
                    nums.push(num);
                    break;
                
                case '+':
                case '-':
                    opers.push(s[i]);
                    break;

                default:
                    num = 0;
                    while (i < n && isdigit(s[i]))
                    {
                        num *= 10;
                        num += s[i] - '0';
                        i++;
                    }
                    i--;
                    nums.push(num);
                    break;
            }
        }
        num = 0;
        while (!opers.empty())
        {
            int op1 = nums.top();
            nums.pop();
            char oper = opers.top();
            opers.pop();
            if (oper == '+') num += op1;
            else num -= op1;
        }
        num += nums.top();
        return num;

    }
};
// @lc code=end

