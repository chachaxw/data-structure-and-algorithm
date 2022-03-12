/*
 * @Author: Chacha
 * @Date: 2022-03-12 11:35:35
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-12 12:11:28
 */

/**
 * 说明：给定一个编码字符，按编码规则进行解码，输出字符串
 *     编码规则是`count[letter]`，将letter的内容count次输出，count是0或正整数，letter是区分大小写的纯字母
 * 示例：
 * const s = '3[a]2[bc]'; decodeString(s); // 返回'aaabcbc'
 * const s = '3[a2[c]]'; decodeString(s); // 返回'accaccacc'
 * const s = '2[abc]3[cd]ef'; decodeString(s); // 返回'abcabccdcdcdef'
 */

/**
 * 题解：
 * 从字符串的规则中，可以很容易发现规律，可以用正则表达式写出字符串 '3[a]2[bc]' 的基本规则，然后根据正则表达式匹配获取
 * 字符串中的的数字和字母，通过递归逐个匹配计算出字符串数量，最终组合成上述形式。
 *
 * @param {string} str
 */
function decodeString(str) {
    var reg = /(\d?)(\[[a-zA-Z]+\])/g;

    if (!reg.test(str)) return str;

    str = str.replace(reg, function (_, p1, p2) {
        var letter = "";

        console.log(p1, p2);

        if (!p1) {
            p1 = 1;
        }

        if (/\d/.test(p1)) {
            for (let i = 0; i < p1; i++) {
                p2 = p2.replace("[", "").replace("]", "");
                letter += p2;
            }
        }

        return letter;
    });

    return decodeString(str);
}

const s1 = "3[a]2[bc]";
const s2 = "3[a2[c]]";
const s3 = "2[Abc]3[Cd]ef";

console.log("====================================");
console.log("Decode string s1 ", decodeString(s1)); // aaabcbc
console.log("====================================");
console.log("Decode string s2 ", decodeString(s2)); // accaccacc
console.log("====================================");
console.log("Decode string s3", decodeString(s3)); // AbcAbcCdCdCdef
console.log("====================================");
