/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */
#include <vector>
#include <queue>
using std::vector;
using std::queue;
// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int> ());
        vector<int> indegree(numCourses, 0);
        vector<int> order;
        // cons graph
        for (auto & pre : prerequisites) 
        {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        // topo sort
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0) q.push(i);
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            order.push_back(node);
            for (auto adj : graph[node])
            {
                indegree[adj]--;
                if (indegree[adj] == 0) q.push(adj);
            }
        }
        return order.size() == numCourses ? order : vector<int> ();
    }
};
// @lc code=end

