/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <vector>
#include <unordered_map>
using std::unordered_map;
using std::vector;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        int pos = 0;
        for (auto i : nums)
        {
            auto it = hash.find(target - i);
            if (it != hash.end())
                return {it->second, pos};
            hash[i] = pos;
            pos++;
        }
        return {};
    }
};
// @lc code=end

