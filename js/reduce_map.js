/*
 * @Author: Chacha
 * @Date: 2022-05-06 17:15:45
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-05-06 19:52:19
 */

/**
 * map: 遍历数组的每一项，并执行回调函数的操作，返回一个对每一项进行操作后的新数组。
 *
 * reduce: 对数组累积执行回调函数，返回最终计算结果。
 *
 * @param {*} callback
 * @param {*} ctx
 * @returns
 *
 */
Array.prototype.map2 = function (callback, ctx = null) {
    if (typeof callback !== "function") {
        throw new Error("callback must be a function");
    }

    return this.reduce(
        (result, cur, index, array) =>
            result.concat(callback.call(ctx, cur, index, array)),
        []
    );
};

let arr = [1, 2];
let arr1 = arr.map2(
    function (it, i, array) {
        console.log(it, i, array, this);
        return it * 2;
    },
    { name: "Chacha" }
);

console.log("====================================");
console.log(arr1);
console.log("====================================");
