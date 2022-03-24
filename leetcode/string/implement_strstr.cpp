/*
 * @Author: Chacha
 * @Date: 2022-03-20 14:32:32
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-20 23:02:34
 */

/**
 * 来源：https://leetcode-cn.com/problems/implement-strstr
 *
 * 实现 strStr() 函数。给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出
 * needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。
 *
 * 说明：
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。
 *
 * 示例 1：
 * 输入：haystack = "hello", needle = "ll"
 * 输出：2
 *
 * 示例 2：
 * 输入：haystack = "aaaaa", needle = "bba"
 * 输出：-1
 *
 * 示例 3：
 * 输入：haystack = "", needle = ""
 * 输出：0
 *
 * 提示：
 * 1. 0 <= haystack.length, needle.length <= 5 * 10^4
 * 2. haystack 和 needle 仅由小写英文字符组成
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
    int strStr(string haystack, string needle);
};

/**
 * KMP算法
 *
 * 什么是KMP?
 * 因为是由这三位学者发明的：Knuth，Morris和Pratt，所以取了三位学者名字的首字母。所以叫做KMP。
 *
 * KMP有什么用？
 * KMP主要应用在字符串匹配上。KMP的主要思想是当出现字符串不匹配时，可以知道一部分之前已经匹配的文本内容，可以利用这些信息避免从头再去做匹配了。
 * 所以如何记录已经匹配的文本内容，是KMP的重点，也是next数组肩负的重任。
 *
 * 什么是前缀表？
 * next数组就是一个前缀表（prefix table）。前缀表有什么作用呢？
 * 前缀表是用来回退的，它记录了模式串与主串(文本串)不匹配的时候，模式串应该从哪里开始重新匹配。
 * 举例说明：
 * 要在文本串：aabaabaafa 中查找是否出现过一个模式串：aabaaf。
 *
 * 文本串：aabaabaafa
 * 模式串：aabaaf
 *
 * 可以看出，文本串中第六个字符b 和 模式串的第六个字符f，不匹配了。如果暴力匹配，会发现不匹配，此时就要从头匹配了。
 * 但如果使用前缀表，就不会从头匹配，而是从上次已经匹配的内容开始匹配，找到了模式串中第三个字符b继续开始匹配。
 *
 * 前缀表是如何记录的呢？首先要知道前缀表的任务是当前位置匹配失败，找到之前已经匹配上的位置，再重新匹配，
 * 此也意味着在某个字符失配时，前缀表会告诉你下一步匹配中，模式串应该跳到哪个位置。
 * 那什么是前缀表：记录下标i之前（包括i）的字符串中，有多大长度的相同前缀后缀
 *
 * 最长公共前后缀？
 * 字符串的前缀是指不包含最后一个字符的所有以第一个字符开头的连续子串。
 * 后缀是指不包含第一个字符的所有以最后一个字符结尾的连续子串。
 * 所以字符串a的最长相等前后缀为0。 字符串aa的最长相等前后缀为1。 字符串aaa的最长相等前后缀为2。
 *
 * 为什么一定要用前缀表？
 *
 *
 */
int Solution::strStr(string haystack, string needle)
{
    return 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
