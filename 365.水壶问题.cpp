/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */
#include <numeric>
using std::gcd;
// @lc code=start
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity) return false;
        if (jug1Capacity == 0 || jug2Capacity == 0) return targetCapacity == 0 || targetCapacity == jug1Capacity + jug2Capacity;
        return (targetCapacity % gcd(jug1Capacity, jug2Capacity)) == 0;
    }
};
// @lc code=end

