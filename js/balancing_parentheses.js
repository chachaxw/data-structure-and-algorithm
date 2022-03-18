/*
 * @Author: Chacha
 * @Date: 2022-03-17 22:55:57
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-17 23:18:41
 */

/**
 * 平衡括号
 *
 * 给定一个由左右括号组成的字符串，"(" 和 ")"，根据需要插入括号来平衡括号。确定必须的最小字符数被插入。
 *
 * 示例 1：
 * 输入：S = '()))'
 * 输出：2
 *
 * 示例 2：
 * 输入：S = '(()))'
 * 输出：1
 *
 */

function minInsertions(str) {
    let bal = 0;
    let ans = 0;

    for (let i = 0; i < str.length; i++) {
        bal += str[i] === "(" ? 1 : -1;

        // 保证 bal >= -1
        if (bal === -1) {
            ans += 1;
            bal += 1;
        }
    }

    return bal + ans;
}

console.log("====================================");
console.log("S = '()))', 最小字符", minInsertions("()))"));
console.log("====================================");

console.log("====================================");
console.log("S = '(()))', 最小字符", minInsertions("(()))"));
console.log("====================================");
