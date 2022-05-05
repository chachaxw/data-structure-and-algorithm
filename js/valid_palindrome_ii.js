/*
 * @Author: Chacha
 * @Date: 2022-05-05 10:48:06
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-05-05 10:54:20
 */

/**
 *
 * 来源：https://leetcode-cn.com/problems/valid-palindrome-ii/
 *
 * 680. 验证回文字符串
 * 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
 *
 * 示例 1:
 * 输入: s = "aba"
 * 输出: true
 *
 * 示例 2:
 * 输入: s = "abca"
 * 输出: true
 * 解释: 你可以删除c字符。
 *
 * 示例 3:
 * 输入: s = "abc"
 * 输出: false
 *
 */

const validPalindrome = (s) => {
    const isPalindrome = (start, end) => {
        while (start < end) {
            if (s[start] !== s[end]) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    };

    let i = 0; // 头指针
    let j = s.length - 1; // 尾指针

    while (i < j && s[i] === s[j]) {
        i++;
        j--;
    }

    if (isPalindrome(i + 1, j)) {
        return true;
    }

    if (isPalindrome(i, j - 1)) {
        return true;
    }

    return false;
};

console.log(validPalindrome("aba"));
console.log(validPalindrome("abca"));
console.log(validPalindrome("abc"));
console.log(validPalindrome("deeee"));
