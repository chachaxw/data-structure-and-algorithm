/*
 * @Author: Chacha
 * @Date: 2022-03-12 20:54:15
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-12 23:50:58
 */

/**
 * 说明：获取一个数字数组中的最大值
 * 示例：
 * 输入：[1, 5, 3, 9, 2, 7]
 * 输出：9
 */
function getMaxFromArray(arr) {
    if (!Array.isArray(arr)) return;

    var max = arr[0];
    arr.forEach(function (item) {
        if (max < item) {
            max = item;
        }
    });

    return max;
}

const arr = [1, 5, 3, 9, 2, 7];

console.log("====================================");
console.log(getMaxFromArray(arr));
console.log("====================================");
