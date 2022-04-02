/*
 * @Author: Chacha
 * @Date: 2022-04-02 13:19:17
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-02 13:27:04
 */

/**
 * 正则表达式匹配
 *
 * 有字符串var='abc345efgabcab',请写出3条js语句分别实现如下3个功能：
 * 1. 去掉字符串中的a、b、c字符，形成结果：'345efg';
 * 2. 将字符串中数字用中括号括起来，形成结果：'abc[3][4][5]efgabcab';
 * 3. 将字符串中每个数字的值分别乘以2，形成结果：abc6810efgabcab;
 */

let x = "abc345efgabcab";
const res1 = x.replace(/[a-c]/g, "");
const res2 = x.replace(/([0-9])/g, "[$1]");
const res3 = x.replace(/([0-9])/g, ($0) => $0 * 2);

console.log("====================================");
console.log(res1);
console.log("====================================");
console.log(res2);
console.log("====================================");
console.log(res3);
console.log("====================================");
