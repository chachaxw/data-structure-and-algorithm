/*
 * @Author: Chacha
 * @Date: 2022-04-03 23:25:18
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-03 23:33:11
 */

/**
 * 选择排序
 *
 * 排序步骤：
 * 1. 取出未排序部分的第一个元素，遍历该元素之后的部分并比较大小。对于第一次遍历，就是取出第一个元素
 * 2. 如果有更小的，与该元素交换位置
 * 3. 每次遍历都能找出剩余元素中的最小值并放在已排序部分的最后
 *
 */

/**
 *
 * @param {[]} arr 数组
 * @param {number} a 下标 a
 * @param {number} b 下标 b
 * @returns {[]}
 */
const swap = (arr, a, b) => ([arr[b], arr[a]] = [arr[a], arr[b]]);

const selectSort = (arr) => {
    const length = arr.length;

    for (let i = 0; i < length; i++) {
        let minIndex = i;

        for (let j = i + 1; j < length; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex !== i) {
            swap(arr, i, minIndex);
        }
    }

    return arr;
};

console.log(selectSort([-1, 10, 10, 2]));
