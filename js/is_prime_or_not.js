/*
 * @Author: Chacha
 * @Date: 2022-03-17 22:06:08
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-17 22:50:58
 */

/**
 * Prime or not?
 *
 * 给定一个整数 n，如果该数是素数，则返回 1。否则返回大于 1 的最小除数。
 *
 * 2 ≤ n ≤ 10^12
 *
 * 示例 1：
 * n = 24;
 * 数字 24 不是素数：它的除数是 (1, 2, 3, 4, 6, 8, 12, 24)。最小除数大于 1，是 2。
 *
 */

function isPrimeOrNot(n) {
    for (let i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return i;
        }
    }

    return 1;
}

console.log("是否是素数", isPrimeOrNot(2));
console.log("是否是素数", isPrimeOrNot(4));
console.log("是否是素数", isPrimeOrNot(7));
console.log("是否是素数", isPrimeOrNot(13));
console.log("是否是素数", isPrimeOrNot(15));
console.log("是否是素数", isPrimeOrNot(24));
console.log("是否是素数", isPrimeOrNot(31));
