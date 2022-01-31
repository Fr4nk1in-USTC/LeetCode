/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ele;
        solve(n, 1, k, ans, ele);
        return ans;
    }
    void solve(int n, int m, int k, vector<vector<int>>& ans, vector<int>& ele)
    {
        if (ele.size() == k)
        {
            vector<int> new_ele = ele;
            ans.push_back(new_ele);
            return;
        }
        if (m > n) return;
        ele.push_back(m);
        solve(n, m+1, k, ans, ele);
        ele.pop_back();
        solve(n, m+1, k, ans, ele);
    }
};
// @lc code=end

