/*
 * @Author: Chacha
 * @Date: 2022-03-28 10:26:36
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-28 10:37:28
 */

/**
 * 验证回文字符串 https://leetcode-cn.com/problems/valid-palindrome/
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 *
 * 示例 1:
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 解释："amanaplanacanalpanama" 是回文串
 *
 * 示例 1:
 * 输入: "race a car"
 * 输出: false
 * 解释："raceacar" 不是回文串
 *
 */

function isPalindrome(str) {
    str = str.replace(/[^a-zA-Z\d]/g, "").toLowerCase();
    const len = str.length;
    let i = 0;

    console.log("====================================");
    console.log(str);
    console.log("====================================");

    while (i < len / 2) {
        if (str[i] !== str[len - 1 - i]) {
            return false;
        }
        i++;
    }

    return true;
}

const str = "A man, a plan, a canal: Panama";
const str1 = "race a car";

console.log("====================================");
console.log("str 是否是回文串：", isPalindrome(str));
console.log("====================================");

console.log("====================================");
console.log("str1 是否是回文串：", isPalindrome(str1));
console.log("====================================");
