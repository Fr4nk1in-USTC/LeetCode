/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using std::getline;
using std::stringstream;
using std::string;
using std::vector;
// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> names;
        stringstream ss(path);
        string word;
        while (getline(ss, word, '/'))
        {
            if (word == "" || word == ".") continue;
            if (word == "..")
            {
                if (!names.empty()) names.pop_back();
                continue;
            }
            names.push_back(word);
        }
        word = "";
        for (auto& str : names)
        {
            word += "/" + str;
        }
        if (word.empty()) return "/";
        else return word;

    }
};
// @lc code=end

