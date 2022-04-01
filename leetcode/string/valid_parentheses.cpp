/*
 * @Author: Chacha
 * @Date: 2022-03-31 21:48:11
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-01 22:39:48
 */

/**
 * 来源：https://leetcode-cn.com/problems/valid-parentheses
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 有效字符串需满足：
 * 1. 左括号必须用相同类型的右括号闭合。
 * 2. 左括号必须以正确的顺序闭合。
 *
 * 示例 1：
 * 输入：s = "()"
 * 输出：true
 *
 * 示例 2：
 * 输入：s = "()[]{}"
 * 输出：true
 *
 * 示例 3：
 * 输入：s = "(]"
 * 输出：false
 *
 * 示例 4：
 * 输入：s = "([)]"
 * 输出：false
 *
 * 示例 5：
 * 输入：s = "{[]}"
 * 输出：true
 *
 */
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
private:
    /* data */
public:
    bool isValid(string s);
};

/**
 * 判断括号的有效性可以使用「栈」这一数据结构来解决。
 * 1. 栈先入后出特点恰好与本题括号排序特点一致，即若遇到左括号入栈，
 *    遇到右括号时将对应栈顶左括号出栈，则遍历完所有括号后 stack 仍然为空。
 * 2. 建立哈希表 pairs 构建左右括号对应关系：key左括号，value右括号；这样查询 2 个括号是否对应，
 *    只需 O(1) 时间复杂度；建立栈 stack，遍历字符串 s 并按照算法流程一一判断
 *
 * 算法流程：
 * 1. 如果 ch 是 左括号，则入栈 push
 * 2. 否则通过哈希表判断括号对应关系，若 stack 栈顶出栈括号 stack.top() 与当前遍历括号 ch 不对应，则提前返回 false
 *
 * 复杂度分析:
 * 时间复杂度：正确的括号组合需要遍历 1 遍 s
 * 空间复杂度：哈希表和栈使用线性的空间大小
 *
 */
bool Solution::isValid(string s)
{
    int n = s.size();

    if (n % 2 == 1)
    {
        return false;
    }

    unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}};

    stack<char> stk;

    for (char ch : s)
    {
        if (pairs.count(ch))
        {
            if (stk.empty() || stk.top() != pairs[ch])
            {
                return false;
            }
            stk.pop();
        }
        else
        {
            stk.push(ch);
        }
    }

    return stk.empty();
}

int main(int argc, char const *argv[])
{

    Solution s;
    string str = "()[]{}";
    string str1 = "([)]";

    cout << "()[]{} 是否闭合: " << s.isValid(str) << endl;
    cout << "([)] 是否闭合: " << s.isValid(str1) << endl;

    return 0;
}
