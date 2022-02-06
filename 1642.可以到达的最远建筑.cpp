/*
 * @lc app=leetcode.cn id=1642 lang=cpp
 *
 * [1642] 可以到达的最远建筑
 */
#include <vector>
#include <queue>
using std::greater;
using std::priority_queue;
using std::vector;
// @lc code=start
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> heap;
        int n = heights.size();
        for (int i = 1; i < n; i++)
        {
            int delta = heights[i] - heights[i - 1];
            if (delta > 0)
            {
                heap.emplace(delta);
                if (heap.size() > ladders)
                {
                    bricks -= heap.top();
                    if (bricks < 0) return i - 1;
                    heap.pop();
                }
            }
        }
        return n - 1;
    }
};
// @lc code=end

