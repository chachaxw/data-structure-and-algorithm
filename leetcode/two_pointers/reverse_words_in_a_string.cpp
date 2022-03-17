/*
 * @Author: Chacha
 * @Date: 2022-03-17 15:01:30
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-17 18:01:59
 */

/**
 * 来源：https://leetcode-cn.com/problems/reverse-words-in-a-string/
 *
 * 151. 颠倒字符串中的单词
 *
 * 给你一个字符串 s ，颠倒字符串中单词的顺序。单词是由非空格字符组成的字符串。
 * s 中使用至少一个空格将字符串中的单词分隔开。返回单词顺序颠倒且单词之间用单个空格连接的结果字符串。
 * 注意：输入字符串 s 中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，
 * 单词间应当仅用单个空格分隔，且不包含任何额外的空格。
 *
 * 提示：
 * 1 <= s.length <= 10^4
 * s 包含英文大小写字母、数字和空格 ' '
 * s 中至少存在一个单词
 *
 * 进阶：如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用 O(1) 额外空间复杂度的 原地 解法。
 *
 * 示例 1：
 * 输入：s = "the sky is blue"
 * 输出："blue is sky the"
 *
 * 示例 2：
 * 输入：s = "  hello world  "
 * 输出："world hello"
 * 解释：颠倒后的字符串中不能存在前导空格和尾随空格。
 *
 * 示例 3：
 * 输入：s = "a good   example"
 * 输出："example good a"
 * 解释：如果两个单词间有多余的空格，颠倒后的字符串需要将单词间的空格减少到仅有一个。
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string reverseWords(string s);

    void removeExtraSpaces(string &s);

    void reverse(string &s, int start, int end);
};

/**
 * 双指针法
 *
 * 解题思路如下：
 * 1. 移除多余空格
 * 2. 将整个字符串反转
 * 3. 将每个单词反转
 *
 * 空间复杂度: O(1)
 *
 */
string Solution::reverseWords(string s)
{
    removeExtraSpaces(s);

    cout << "移除空格之后" << s << endl;

    reverse(s, 0, s.size() - 1);

    cout << "处理字符串之后" << s << endl;

    for (int i = 0; i < s.size(); i++)
    {
        int j = i;

        while (j < s.size() && s[j] != ' ')
            j++;

        reverse(s, i, j - 1);
        i = j;
    }

    cout << "颠倒字符串之后" << s << endl;

    return s;
};

/**
 * 快慢指针法移除多余空格
 */
void Solution::removeExtraSpaces(string &s)
{
    int i = 0, j = 0;

    // 去掉字符串前面的空格
    while (s.size() > 0 && j < s.size() && s[j] == ' ')
    {
        j++;
    }

    for (; j < s.size(); j++)
    {
        // 去掉字符串中间部分的冗余空格
        if (j - 1 > 0 && s[j - 1] == s[j] && s[j] == ' ')
        {
            continue;
        }
        else
        {
            s[i++] = s[j];
        }
    }

    if (i - 1 > 0 && s[i - 1] == ' ')
    { // 去掉字符串末尾的空格
        s.resize(i - 1);
    }
    else
    {
        s.resize(i); // 重新设置字符串大小
    }
}

/**
 * 双指针法翻转字符串
 *
 * 反转字符串s中左闭又闭的区间[start, end]
 *
 */
void Solution::reverse(string &s, int start, int end)
{
    for (int i = start, j = end; i < j; i++, j--)
    {
        swap(s[i], s[j]);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "the sky is blue";
    string str1 = "   hello world    ";

    s.reverseWords(str);
    s.reverseWords(str1);

    return 0;
}
