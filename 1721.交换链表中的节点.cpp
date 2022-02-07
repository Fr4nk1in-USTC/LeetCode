/*
 * @lc app=leetcode.cn id=1721 lang=cpp
 *
 * [1721] 交换链表中的节点
 */
#include <algorithm>
using std::swap;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *fast = head, *slow = head;
        ListNode *node1, *node2;
        for (int i = 1; i < k; i++) fast = fast->next;
        node1 = fast;
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        node2 = slow;
        if (node1 != node2) swap(node1->val, node2->val);
        return head;
    }
};
// @lc code=end

