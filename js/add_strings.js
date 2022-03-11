/*
 * @Author: Chacha
 * @Date: 2022-03-10 23:47:10
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-11 15:44:23
 */

/**
 * 来源：https://leetcode-cn.com/problems/add-strings/
 *
 * 给定两个字符串形式的非负整数 num1 和 num2 ，计算它们的和并同样以字符串形式返回。
 * 你不能使用任何內建的用于处理大整数的库（比如 BigInteger），也不能直接将输入的字符串转换为整数形式。
 *
 * 1. 1 <= num1.length, num2.length <= 104
 * 2. num1 和num2 都只包含数字 0-9
 * 3. num1 和num2 都不包含任何前导零
 *
 *
 * 示例 1：
 * 输入：num1 = "11", num2 = "123"
 * 输出："134"
 *
 * 示例 2：
 * 输入：num1 = "456", num2 = "77"
 * 输出："533"
 *
 * 示例 3：
 * 输入：num1 = "0", num2 = "0"
 * 输出："0"
 *
 */

/**
 * 双指针法
 * 我们可以使用双指针来模拟人工计算，步骤如下：
 * 1. 创建指针 i 指向 num1 末位数字，j 指向 num2 末位数字
 * 2. i，j数字相加，用 carry 来记录进位值，没有则为0
 * 3. 若产生进位，则当前数字为 (i + j) % 10的值
 * 4. 若遍历过程中，num1 或 num2 当前无数字，则用 0 来补位
 *
 * num1:   4  5  6
 * num2:   0  7  7
 * ans:    5  3  3
 *
 *
 * @param {string} num1
 * @param {string} num2
 */
function addStrings(num1, num2) {
    let i = num1.length - 1,
        j = num2.length - 1,
        carry = 0, // 代表进位值
        ans = [];

    while (i >= 0 || j >= 0 || carry != 0) {
        let c1 = i >= 0 ? num1.charAt(i) - "0" : 0,
            c2 = j >= 0 ? num2.charAt(j) - "0" : 0;

        let sum = c1 + c2 + carry;
        ans.push(sum % 10);
        carry = Math.floor(sum / 10);
        i--;
        j--;
    }

    return ans.reverse().join("");
}

console.log(
    "num1 = '11', num2 = '123', num1 + num2 =",
    addStrings("11", "123")
);
console.log(
    "num1 = '456', num2 = '77', num1 + num2 =",
    addStrings("456", "77")
);
console.log(
    "num1 = '179', num2 = '11', num1 + num2 =",
    addStrings("179", "11")
);
