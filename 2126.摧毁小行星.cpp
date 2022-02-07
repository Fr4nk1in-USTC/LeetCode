/*
 * @lc app=leetcode.cn id=2126 lang=cpp
 *
 * [2126] 摧毁小行星
 */
#include <vector>
#include <algorithm>
using std::vector;
using std::sort;
// @lc code=start
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long mass1 = mass;
        for (int asteroid : asteroids)
        {
            if (asteroid > mass1) return false;
            mass1 += asteroid;
        }
        return true;
    }
};
// @lc code=end

