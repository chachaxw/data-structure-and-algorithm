/*
 * @Author: Chacha
 * @Date: 2022-04-04 16:55:30
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-04 17:06:03
 */

/**
 * 快速排序
 * 1. 选择一个基准元素 pivot，比如第一个元素
 * 2. 遍历数组，比 pivot 更小的元素创建一个数组，更大的创建一个数组，相等的也创建一个数组
 * 3. 递归大小两个数组，继续执行1，直到数组只剩1个元素；递归的同时把这三部分连接起来
 *
 */

/**
 * 快速排序
 * @param {[]} array
 * @returns {[]} array
 */
const quickSort = (array) => {
    const length = array.length;

    if (length <= 1) {
        return array;
    }

    const pivotIndex = Math.floor(length / 2); // 基准元素下标
    const pivotValue = array.splice(pivotIndex, 1)[0];
    let leftArray = [],
        rightArray = [],
        index = 0;

    while (index < length - 1) {
        const currentValue = array[index];

        if (currentValue <= pivotValue) {
            leftArray.push(currentValue);
        } else {
            rightArray.push(currentValue);
        }

        index++;
    }

    return quickSort(leftArray).concat([pivotValue], quickSort(rightArray));
};

const arr = [-10, 10, 1, 34, 5, 1];

console.log(quickSort(arr)); // 输出 [ -10, 1, 1, 5, 10, 34 ]
