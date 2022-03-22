/*
 * @Author: Chacha
 * @Date: 2022-03-22 10:54:56
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-22 13:17:39
 */

//
// 函数 createWeightedSampling 接收一个整数数组 arr, 此数组元素个数
// N < 10000, 元素的值大于 0 且小于 100. 返回一个随机函数, 此随机
// 函数返回 [0, N - 1] 之间的一个随机整数. 每个整数 i 被返回的概率为
// 数组 arr 的第 i 个元素的值 / 数组 arr 的所有元素之和.
//
// 例: 给定一个数组 input, 值为 [4, 2, 1, 3],
// 调用 createWeightedSampling(input),
// 返回一个函数, 此函数返回一个 0 - 3 之间的一个随机整数, 相应的概率
// 分别为 4/10, 2/10, 1/10, 3/10.
//
// 在保证时间复杂度为 O(1) 的前提下, 尽可能优化性能
//
/**
 * 加权平均数
 * 先计算出每个数据项的权重，然后依据权重依次将每个数据项放入一个数组中，数据项在数组中的个数与数据项的权重呈正相关，
 * 为了简便，也可以将数据项的索引放到数组中，比如一组数据的权重依次是 4 2 1 3，则可以生成这样一个数组：
 * [0, 0, 0, 0, 1, 1, 2, 3, 3, 3]，生成数组后，从数组中随机选出一个作为结果。
 *
 * @param {number[]} input
 */
function createWeightedSampling(input) {
    let data = [];
    let sum = input.reduce((prev, curr) => prev + curr);
    const length = input.length;

    for (let i = 0; i < length; i++) {
        for (let j = 0; j < input[i]; j++) {
            data.push(i);
        }
    }

    console.log("加权后的数据", data);

    return () => {
        let index = Math.floor(Math.random() * sum);
        return data[index];
    };
}

const arr = [4, 2, 1, 3];
const count = [0, 0, 0, 0];
const sampling = createWeightedSampling(arr);

for (let i = 0; i < 10000; i++) {
    count[sampling()]++;
}

const rates = count.map((i) => Math.round(i / 1000));

console.log("概率", count, rates);
console.assert(JSON.stringify(rates) === "[4,2,1,3]");
