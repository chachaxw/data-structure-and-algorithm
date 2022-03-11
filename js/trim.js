/*
 * @Author: Chacha
 * @Date: 2022-03-11 14:31:57
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-11 15:40:45
 */

/**
 * JS 实现 trim 函数
 */

String.prototype.trim1 = function () {
    return this.replace(/^\s\s*/, "").replace(/^\s\s*$/, "");
};

String.prototype.trim2 = function () {
    var str = this;

    whitespace =
        " \n\r\t\f\x0b\xa0\u2000\u2001\u2002\u2003\u2004\u2005\u2006\u2007\u2008\u2009\u200a\u200b\u2028\u2029\u3000";

    for (let i = 0, len = str.length; i < len; i++) {
        if (whitespace.indexOf(str.charAt(i)) === -1) {
            str = str.substring(i);
            break;
        }
    }

    for (let i = str.length - 1; i >= 0; i--) {
        if (whitespace.indexOf(str.charAt(i)) === -1) {
            str = str.substring(0, i + 1);
            break;
        }
    }

    return whitespace.indexOf(str.charAt(0)) === -1 ? str : "";
};

let hello = "        hello world         ";

console.log(hello);
console.log("Trim result is", hello.trim1());
console.log("Trim result is", hello.trim2());
