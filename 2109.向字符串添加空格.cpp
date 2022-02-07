/*
 * @lc app=leetcode.cn id=2109 lang=cpp
 *
 * [2109] 向字符串添加空格
 */
#include <string>
#include <vector>
using std::string;
using std::vector;
// @lc code=start
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size(), m = spaces.size();
        string ans;
        ans.resize(m + n);
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i + m] = s[i];
            if (m > 0 && i == spaces[m - 1]) ans[i + --m] = ' ';
        }
        return ans;
    }
};
// @lc code=end

