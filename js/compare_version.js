/*
 * @Author: Chacha
 * @Date: 2022-03-12 16:35:07
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-12 16:45:57
 */

/**
 * 说明：实现一个方法，用于比较两个版本号（version1、version2）
 *     如果version1 > version2，返回1；如果version1 < version2，返回-1，其他情况返回 0
 *     版本号规则`x.y.z`，xyz均为大于等于0的整数，至少有x位
 * 示例：
 * compareVersion('0.1', '1.1.1'); // 返回-1
 * compareVersion('13.37', '1.2 '); // 返回1
 * compareVersion('1.1', '1.1.0'); // 返回0
 */

/**
 * 将 version1 和 version2转化成数组，然后对数组的每一项进行比较大小。
 *
 * @param {string} version1
 * @param {string} version2
 * @returns
 */
function compareVersion(version1, version2) {
    var v1 = version1.split(".");
    var v2 = version2.split(".");

    var length = Math.max(v1.length, v2.length);

    for (var i = 0; i < length; i++) {
        var num1 = i < v1.length ? Number(v1[i]) : 0;
        var num2 = i < v2.length ? Number(v2[i]) : 0;

        var n = num1 - num2;

        if (n < 0) {
            return -1;
        } else if (n > 0) {
            return 1;
        }
    }

    return 0;
}

console.log(compareVersion("0.1", "1.1.1"));
console.log(compareVersion("13.37", "1.2 "));
console.log(compareVersion("1.1", "1.1.0"));
