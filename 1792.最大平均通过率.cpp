/*
 * @lc app=leetcode.cn id=1792 lang=cpp
 *
 * [1792] 最大平均通过率
 */
#include <vector>
#include <queue>
#include <tuple>
using std::tuple;
using std::priority_queue;
using std::vector;
// @lc code=start
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double, int, int>> heap;
        auto diff = [](int x, int y) -> double 
        {
            return (double) (x + 1) / (y + 1) - (double) x / y;
        };
        double ans = 0;
        for (const auto & c : classes)
        {
            int x = c[0], y = c[1];
            ans += (double) x / y;
            heap.emplace(diff(x, y), x, y);
        }
        for (int i = 0; i < extraStudents; i++)
        {
            auto [d, x, y] = heap.top();
            heap.pop();
            ans += d;
            heap.emplace(diff(x + 1, y + 1), x + 1, y + 1);
        }
        return ans / classes.size();
    }
};
// @lc code=end

