/*
 * @lc app=leetcode.cn id=2150 lang=cpp
 *
 * [2150] 找出数组中的所有孤独数字
 */
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;
// @lc code=start
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> hashmap;
        for (int num : nums) hashmap[num]++;
        for (int num : nums) 
        {
            if (hashmap[num] == 1 && hashmap[num - 1] == 0 && hashmap[num + 1] == 0) ans.push_back(num);
        }
        return ans;
    }
};
// @lc code=end

