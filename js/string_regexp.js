/*
 * @Author: Chacha
 * @Date: 2022-04-02 13:19:17
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-02 13:45:03
 */

/**
 * 正则表达式匹配
 *
 * 有字符串var='abc345efgabcab',请写出3条js语句分别实现如下3个功能：
 * 1. 去掉字符串中的a、b、c字符，形成结果：'345efg';
 * 2. 将字符串中数字用中括号括起来，形成结果：'abc[3][4][5]efgabcab';
 * 3. 将字符串中每个数字的值分别乘以2，形成结果：abc6810efgabcab;
 */

const x = "abc345efgabcab";
const res1 = x.replace(/[a-c]/g, "");
const res2 = x.replace(/([0-9])/g, "[$1]");
const res3 = x.replace(/([0-9])/g, ($0, $1) => $1 * 2);

console.log("====================================");
console.log(res1);
console.log("====================================");
console.log(res2);
console.log("====================================");
console.log(res3);
console.log("====================================");

/**
 * 将字符串 "abc12345#$*%" 变成 "abc-12345-#$*%"
 */

const string = "abc12345#$*%";

/**
 * replace 回调函数参数意义：
 * 1. match - 匹配的子串
 * 2. p1, p2, ... - 假如 replace() 方法的第一个参数是一个 RegExp 对象，则代表第 n 个括号匹配的字符串。
 *    例如，如果用 /(\a+)(\b+)/ 这个来匹配，p1 就是匹配的 \a+，p2 就是匹配 \b+
 * 3. offset - 匹配到的子字符串在原字符串中的偏移量。比如，如果原字符串是 'abcd'，
 *    匹配到的子字符串是 'bc'，那么这个参数将会是 1
 * 4. string - 被匹配的原字符串
 *
 */
const res4 = string.replace(
    /([^\d]*)(\d*)([^\w*]*)/,
    (match, p1, p2, p3, offset, string) => {
        console.log("match", match);
        console.log("p1", p1);
        console.log("p2", p2);
        console.log("p3", p3);
        console.log("offset", offset);
        console.log("string", string);

        return p1 + "-" + p2 + "-" + p3;
    }
);

console.log("====================================");
console.log(res4);
console.log("====================================");
