/*
 * @Author: Chacha
 * @Date: 2022-04-02 22:32:27
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-02 22:55:48
 */

/**
 * 来源：https://leetcode-cn.com/problems/reverse-integer/
 *
 * 整数反转
 * 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
 * 如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。
 * 假设环境不允许存储 64 位整数（有符号或无符号）。
 *
 * 示例 1：
 * 输入：x = 123
 * 输出：321
 *
 * 示例 2：
 * 输入：x = -123
 * 输出：-321
 *
 * 示例 3：
 * 输入：x = 120
 * 输出：21
 *
 * 示例 4：
 * 输入：x = 0
 * 输出：0
 *
 */

/**
 * @param {number} num
 * @returns {number}
 */
const reverseNum = (num) => {
    let result = 0;

    while (num != 0) {
        result = result * 10 + (num % 10);

        if (result > Infinity || result < -Infinity) return 0;

        // ~~会把后面的表达式强行变成int
        num = ~~(num / 10);
    }

    return result;
};

console.log("x = 123, 反转之后", reverseNum(123));
console.log("x = -123, 反转之后", reverseNum(-123));
console.log("x = 120, 反转之后", reverseNum(120));
console.log("x = 0, 反转之后", reverseNum(0));
