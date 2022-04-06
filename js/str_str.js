/*
 * @Author: Chacha
 * @Date: 2022-04-02 20:14:54
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-02 20:24:39
 */

/**
 * 实现 strStr() 函数。
 *
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。
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
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/implement-strstr
 *
 */

const strStr = (haystack, needle) => {
    const l1 = haystack.length;
    const l2 = needle.length;
    let i = 0;

    while (i < l1) {
        const value = haystack.substr(i, l2);

        console.log(value);

        if (value == needle) {
            return i;
        }

        i++;
    }

    return -1;
};

const haystack = "hello";
const haystack1 = "aaaaa";
const haystack2 = "aabaabaafa";
const needle = "ll";
const needle1 = "bba";
const needle2 = "aabaaf";

console.log(strStr(haystack, needle)); // 2
console.log(strStr(haystack1, needle1)); // -1
console.log(strStr(haystack2, needle2)); // 3
