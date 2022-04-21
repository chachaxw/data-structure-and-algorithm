/*
 * @Author: Chacha
 * @Date: 2022-04-21 22:39:49
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-21 22:41:42
 */

/**
 * 283. 移动零 https://leetcode-cn.com/problems/move-zeroes/
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 *
 * 示例:
 * 输入: [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 * 说明: 必须在原数组上操作，不能拷贝额外的数组。尽量减少操作次数。
 *
 */

// 思路就是将非零的不断往前移动，零的不断往后移动
const moveZeroes = (nums) => {
    let len = nums.length;
    let j = 0;

    for (let i = 0; i < len; i++) {
        if (nums[i] !== 0) {
            let temp = nums[i];

            nums[i] = nums[j];
            nums[j] = temp;

            j++;
        }
    }

    return nums;
};

console.log("====================================");
console.log(moveZeroes([0, 1, 0, 3, 12]));
console.log("====================================");
