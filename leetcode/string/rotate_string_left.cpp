/*
 * @Author: Chacha
 * @Date: 2022-03-20 13:26:59
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-20 13:54:43
 */

/**
 * 来源：https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
 *
 * 剑指 Offer 58 - II.左旋转字符串
 * 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
 * 比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
 *
 * 1 <= k < s.length <= 10000
 *
 * 示例 1：
 * 输入: s = "abcdefg", k = 2
 * 输出: "cdefgab"
 *
 * 示例 2：
 * 输入: s = "lrloseumgh", k = 6
 * 输出: "umghlrlose"
 *
 */
#include <string>
#include <iostream>

using namespace std;

class Solution
{
private:
    /* data */
public:
    string reverseStringLeft(string s, int n);
};

/**
 *
 * 可以通过 局部反转+整体反转 达到左旋转的目的。具体步骤为：
 * 1. 反转区间为前 k 的子串
 * 2. 反转区间为 k 到末尾的子串
 * 3. 反转整个字符串
 *
 * 最后就可以得到左旋n的目的，而不用定义新的字符串，完全在本串上操作。
 *
 * 示例 1：
 *
 * 字符串：           a    b  |  c    d    e    f    g
 * 反转 0 到 k-1：    b    a  |  c    d    e    f    g
 * 反转 k 到 len-1：  b    a  |  g    f    e    d    c
 * 反转整个字符串:     c    d     e    f    g    a    b
 *
 * 最后得到 cdefgab
 *
 */
string Solution::reverseStringLeft(string s, int k)
{
    reverse(s.begin(), s.begin() + k);
    reverse(s.begin() + k, s.end());
    reverse(s.begin(), s.end());
    return s;
}

int main(int argc, char const *argv[])
{
    Solution s;

    string str1 = "abcdefg";
    string str2 = "lrloseumgh";

    cout << "abcdefg 在 k = 2 反转后：" << s.reverseStringLeft(str1, 2) << endl;    // cdefgab
    cout << "lrloseumgh 在 k = 6 反转后：" << s.reverseStringLeft(str2, 6) << endl; // umghlrlose

    return 0;
}
