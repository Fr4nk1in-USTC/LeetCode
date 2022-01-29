/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* p = ans;
        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1 == nullptr)
            {
                p->val += l2->val;
                p->next = new ListNode(p->val / 10);
                p->val %= 10;
                p = p->next;
                l2 = l2->next;
                continue;
            }
            if (l2 == nullptr)
            {
                p->val += l1->val;
                p->next = new ListNode(p->val / 10);
                p->val %= 10;
                p = p->next;
                l1 = l1->next;
                continue;
            }
            p->val += l1->val + l2->val;
            p->next = new ListNode(p->val / 10);
            p->val %= 10;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        p = ans;
        while (p->next->next != nullptr) p = p->next;
        if (p->next->val == 0)
        {
            delete p->next;
            p->next = nullptr;
        }
        return ans;
    }
};
// @lc code=end

