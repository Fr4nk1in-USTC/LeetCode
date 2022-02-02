/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include <vector>
#include <queue>
using std::vector;
using std::queue;
// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int> ());
        vector<int> indegree(numCourses, 0);
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
        int visited = 0;
        while (!q.empty())
        {
            visited++;
            int node = q.front();
            q.pop();
            for (auto adj : graph[node])
            {
                indegree[adj]--;
                if (indegree[adj] == 0) q.push(adj);
            }
        }
        return visited == numCourses;
    }
};
// @lc code=end

