/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using std::stack;
using std::vector;
using std::string;
using std::stoi;
// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int op1, op2;
        for (auto &token : tokens)
        {
            if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
            {
                s.push(stoi(token));
                continue;
            }
            op2 = s.top();
            s.pop();
            op1 = s.top();
            s.pop();
            switch (token[0])
            {
                case '+':
                    s.push(op1 + op2);
                    break;
                case '-':
                    s.push(op1 - op2);
                    break;
                case '*':
                    s.push(op1 * op2);
                    break;
                case '/':
                    s.push(op1 / op2);
                    break;
            }
        }
        return s.top();
    }
};
// @lc code=end

