/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */
#include <queue>
#include <vector>
#include <algorithm>
using std::greater;
using std::less;
using std::priority_queue;
using std::vector;
// @lc code=start
class MedianFinder
{
private:
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

public:
    MedianFinder()
    {
        max_heap.push(INT_MIN);
        min_heap.push(INT_MAX);
    }

    void addNum(int num)
    {
        if (max_heap.size() == min_heap.size())
        {
            if (num <= min_heap.top()) max_heap.push(num);
            else
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
        }
        else
        {
            if (num >= max_heap.top()) min_heap.push(num);
            else
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
        }
    }

    double findMedian()
    {
        if (max_heap.size() == min_heap.size())
            return (max_heap.top() + min_heap.top()) / 2.0;
        else return max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
