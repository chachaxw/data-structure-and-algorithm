/*
 * @Author: Chacha
 * @Date: 2022-03-20 14:32:32
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-26 15:51:40
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

    void getNext(int *next, const string &s);
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
 * 文本串：    a   a   b   a   a   b   a   a   f   a
 * 模式串：    a   a   b   a   a   f
 * 下标:      0   1   2   3   4   5
 *
 * 为什么使用前缀表可以告诉我们匹配失败之后跳到哪里重新匹配?
 * 下标5之前这部分的字符串（也就是字符串aabaa）的最长相等的前缀 和 后缀字符串是 子字符串 aa，
 * 因为找到了最长相等的前缀和后缀，匹配失败的位置是后缀子串的后面（即字符 f 之后），
 * 那么我们找到与其相同的前缀的后面从新匹配就可以了。所以前缀表具有告诉我们当前位置匹配失败，跳到之前已经匹配过的地方的能力。
 *
 * 如何计算前缀表？
 * 注意：字符串的前缀是指不包含最后一个字符的所有以第一个字符开头的连续子串；后缀是指不包含第一个字符的所有以最后一个字符结尾的连续子串
 *
 * 如下：
 * 模式串：    a   a   b   a   a   f
 * 下标:      0   1   2   3   4   5
 * 前缀表:    0   1   0   1   2   0
 *
 * 长度为前1个字符的子串a，最长相同前后缀的长度为0
 * 长度为前2个字符的子串aa，最长相同前后缀的长度为1
 * 长度为前3个字符的子串aab，最长相同前后缀的长度为0
 * 长度为前4个字符的子串aaba，最长相同前后缀的长度为1
 * 长度为前5个字符的子串aabaa，最长相同前后缀的长度为2
 * 长度为前6个字符的子串aabaaf，最长相同前后缀的长度为0
 *
 * 可以看出模式串与前缀表对应位置的数字表示的就是：下标i之前（包括i）的字符串中，有多大长度的相同前缀后缀。
 *
 * 文本串：    a   a   b   a   a   b   a   a   f   a
 * 模式串：    a   a   b   a   a   f
 * 下标:      0   1   2   3   4   5
 * 前缀表:    0   1   0   1   2   0
 *
 * 找到的不匹配的位置， 那么此时我们要看它的前一个字符的前缀表的数值是多少。
 * 上述图中，前一个字符的前缀表的数值是2，所有把下标移动到下标2的位置继续匹配。
 *
 * 前缀表与next数组
 * 很多KMP算法的时间都是使用next数组来做回退操作，那么next数组与前缀表有什么关系呢？
 * next数组可以就是前缀表，也可以是前缀表统一减1（右移一位，初始位置为-1）。
 *
 * 使用next数组来匹配
 * 以下我们以前缀表统一减一之后的next数组来做演示。有了next数组，就可以根据next数组来 匹配文本串s，和模式串t了。
 * 注意next数组是新前缀表（旧前缀表统一减1得来）
 *
 * 匹配过程如下：
 * i：         0   1   2   3   4   5   6   7   8   9
 * 文本串：     a   a   b   a   a   b   a   a   f   a
 * 模式串：     a   a   b   a   a   f
 * j+1:       0   1   2   3   4   5
 * 前缀表:     0   1   0   1   2   0
 * next[j]:  -1   0  -1   0   1   0
 *
 * 时间复杂度分析
 * 其中 n 为文本串长度，m为模式串长度，因为在匹配的过程中，根据前缀表不断调整匹配的位置，
 * 可以看出匹配的过程是 O(n)，之前还要单独生成next数组，时间复杂度是 O(m)。
 * 所以整个KMP算法的时间复杂度是 O(n+m) 的。暴力的解法显而易见是 O(n × m)，
 * 所以KMP在字符串匹配中极大的提高的搜索的效率。
 *
 * 构造next数组
 * 我们定义一个 getNext 来构建 next 数组，函数参数为指向next数组的指针，和一个字符串。代码如下：
 * void getNext(int* next, const string& s)
 *
 * 构造next数组其实就是计算模式串s，前缀表的过程。主要有如下三个步骤：
 * 1. 初始化
 * 2. 处理前后缀不相同的情况
 * 3. 处理前后缀相同的情况
 *
 * 详解：
 * 1. 初始化：
 *    定义两个指针 i 和 j，j 指向前缀起始位置，i 指向后缀起始位置。然后还要对next数组进行初始化赋值，如下：
 *    int j = -1; next[0] = j;
 *    next[i] 表示 i(包括i)之前的最长相等的前后缀长度（其实就是 j）。
 *
 *    next[i]:   -1   0  -1   0   1   0
 *    模式串：     a   a   b   a   a   f
 *    下标:       0   1   2   3   4   5
 *               ^   ^
 *              j+1  i
 *
 * 2. 处理前后缀不相同的情况
 *    因为j初始化为-1，那么i就从1开始，进行s[i] 与 s[j+1]的比较。所以遍历模式串s的循环下标 i 要从 1 开始，代码如下：
 *    for (int i = 1; i < s.size(); i++) {}
 *
 *    如果 s[i] 与 s[j+1]不相同，也就是遇到前后缀末尾不相同的情况，就要向前回退。怎么回退呢？
 *    next[j]就是记录着j（包括j）之前的子串的相同前后缀的长度。那么 s[i] 与 s[j+1] 不相同，
 *    就要找 j+1前一个元素在next数组里的值（就是next[j]）。所以，处理前后缀不相同的情况代码如下：
 *    while (j >= 0 && s[i] != s[j+1]) {
 *        j = next[j]; // 向前回退
 *    }
 *
 * 3. 处理前后缀相同的情况
 *    如果 s[i] 与 s[j + 1] 相同，那么就同时向后移动 i 和 j 说明找到了相同的前后缀，
 *    同时还要将 j（前缀的长度）赋给next[i], 因为next[i]要记录相同前后缀的长度。代码如下：
 *    if (s[i] == s[j + 1]) { // 找到相同的前后缀
 *        j++;
 *    }
 *    next[i] = j;
 *
 *    最后整体构建next数组的函数代码如下 void Solution::getNext(int *next, const string &s)
 *
 * 使用next数组来做匹配
 * 在文本串s里找是否出现过模式串 t。定义两个下标 j 指向模式串起始位置，i 指向文本串起始位置。
 * 那么 j 初始值依然为-1，为什么呢？ 依然因为next数组里记录的起始位置为-1。i 就从 0 开始，遍历文本串，代码如下：
 * for (int i = 0; i < s.size(); i++)
 *
 * 接下来就是 s[i] 与 t[j + 1] （因为j从-1开始的） 进行比较。如果 s[i] 与 t[j + 1] 不相同，
 * j 就要从next数组里寻找下一个匹配的位置。代码如下：
 * while(j >= 0 && s[i] != t[j + 1]) {
 *     j = next[j];
 * }
 *
 * 如果 s[i] 与 t[j + 1] 相同，那么 i 和 j 同时向后移动， 代码如下：
 * if (s[i] == t[j + 1]) {
 *     j++; // i的增加在for循环里
 * }
 *
 * 如何判断在文本串s里出现了模式串t呢，如果j指向了模式串t的末尾，那么就说明模式串t完全匹配文本串s里的某个子串了。
 * 本题要在文本串字符串中找出模式串出现的第一个位置 (从0开始)，所以返回当前在文本串匹配模式串的位置i 减去 模式串的长度，
 * 就是文本串字符串中出现模式串的第一个位置。代码如下：
 * if (j == (t.size() - 1) ) {
 *     return (i - t.size() + 1);
 * }
 *
 * 那么使用next数组，用模式串匹配文本串的整体代码如下：
 *
 */
int Solution::strStr(string haystack, string needle)
{
    if (needle.size() == 0)
    {
        return 0;
    }

    int next[needle.size()];

    getNext(next, needle);

    int j = -1;

    for (int i = 0; i < haystack.size(); i++)
    {
        while (j >= 0 && haystack[i] != needle[j + 1])
        {
            // 如果不匹配，j 寻找之前匹配的位置
            j = next[j];
        }

        if (haystack[i] == needle[j + 1])
        {
            // 如果匹配，j和i同时向后移动
            j++;
        }

        if (j == needle.size() - 1)
        {
            // 文本串 haystack 里出现了模式串 needle
            return (i - needle.size() + 1);
        }
    }

    return -1;
}

void Solution::getNext(int *next, const string &s)
{
    int j = -1;
    next[0] = j;

    for (int i = 1; i < s.size(); i++)
    {
        while (j >= 0 && s[i] != s[j + 1])
        {
            // 如果前后缀不相同的，那么就向前回退
            j = next[j];
        }

        if (s[i] == s[j + 1]) // 找到相同的前后缀
        {
            j++;
        }

        next[i] = j; // 将 j（前缀的长度）赋给next[i]
    }
}

int main(int argc, char const *argv[])
{
    Solution s;
    string haystack = "aabaabaafa";
    string haystack1 = "hello";
    string haystack2 = "aaaaa";
    string needle = "aabaaf";
    string needle1 = "ll";
    string needle2 = "bba";

    cout << s.strStr(haystack, needle) << endl;   // 输出 3
    cout << s.strStr(haystack1, needle1) << endl; // 输出 2
    cout << s.strStr(haystack2, needle2) << endl; // 输出 -1

    return 0;
}