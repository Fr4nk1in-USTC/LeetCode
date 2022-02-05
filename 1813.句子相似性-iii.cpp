/*
 * @lc app=leetcode.cn id=1813 lang=cpp
 *
 * [1813] 句子相似性 III
 */
#include <string>
using std::string;
#include <deque>
using std::deque;
#include <algorithm>
using std::swap;
#include <sstream>
using std::stringstream;
// @lc code=start
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.size() < sentence2.size()) swap(sentence1, sentence2);
        if (sentence1 == sentence2) return true;
        stringstream s1(sentence1);
        stringstream s2(sentence2);
        deque<string> words1, words2;
        string word;
        while(s1 >> word) words1.emplace_back(word);
        while(s2 >> word) words2.emplace_back(word);
        while (true)
        {
            if (!words2.empty() && words1.front() == words2.front())
            {
                words1.pop_front();
                words2.pop_front();
            }
            else if (!words2.empty() && words1.back() == words2.back())
            {
                words1.pop_back();
                words2.pop_back();
            }
            else break;
        }
        return words2.empty();
    }
};
// @lc code=end

