/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#include <vector>
#include <algorithm>
using std::vector;
using std::min;

// @lc code=start
class Solution {
public:
    int getKthElement(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        int idx1 = 0, idx2 = 0;
        while (true)
        {
            if (idx1 == m) return nums2[idx2 + k - 1];
            if (idx2 == n) return nums1[idx1 + k - 1];
            if (k == 1) return min(nums1[idx1], nums2[idx2]);
            int new_idx1 = min(idx1 + k / 2 - 1, m - 1);
            int new_idx2 = min(idx2 + k / 2 - 1, n - 1);
            if (nums1[new_idx1] < nums2[new_idx2])
            {
                k -= new_idx1 - idx1 + 1;
                idx1 = new_idx1 + 1;
            }
            else
            {
                k -= new_idx2 - idx2 + 1;
                idx2 = new_idx2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        if (len & 1) return getKthElement(nums1, nums2, (len + 1) >> 1);
        else return (getKthElement(nums1, nums2, len >> 1) + getKthElement(nums1, nums2, (len >> 1) + 1)) / 2.0;
    }
};
// @lc code=end

