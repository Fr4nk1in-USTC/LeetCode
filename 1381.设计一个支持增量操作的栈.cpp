/*
 * @lc app=leetcode.cn id=1381 lang=cpp
 *
 * [1381] 设计一个支持增量操作的栈
 */
#include <algorithm>
#include <cstring>
using std::min;
// @lc code=start
class CustomStack {
private:
    int *base;
    int *add;
    int size;
    int length;
public:
    CustomStack(int maxSize) {
        base = new int[maxSize];
        add = new int[maxSize];
        memset(base, 0, maxSize * sizeof(int));
        memset(add, 0, maxSize * sizeof(int));
        size = maxSize;
        length = 0;
    }
    
    void push(int x) {
        if (length < size) base[length++] = x;
    }
    
    int pop() {
        if (length == 0) return -1;
        int ret = add[length - 1] + base[length - 1];
        length --;
        if (length != 0) add[length - 1] += add[length];
        add[length] = 0;
        return ret;
    }
    
    void increment(int k, int val) {
        int range = min(k, length);
        if (range > 0) add[range - 1] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// @lc code=end

