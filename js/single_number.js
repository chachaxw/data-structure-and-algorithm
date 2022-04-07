/*
 * @Author: Chacha
 * @Date: 2022-04-07 13:44:05
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-07 14:08:25
 */

/**
 * 来源：https://leetcode-cn.com/problems/single-number
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 *
 * 说明：你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 *
 * 示例 1:
 * 输入: [2,2,1]
 * 输出: 1
 *
 * 示例 2:
 * 输入: [4,1,2,1,2]
 * 输出: 4
 *
 */

// 异或的运算法则为：0⊕0=0，1⊕0=1，0⊕1=1，1⊕1=0（同为0，异为1）
const singleNumber = (nums) => {
    let ans = 0;

    for (const num of nums) {
        // 异或计算
        ans = ans ^ num;
    }

    return ans;
};

console.log(singleNumber([2, 2, 1]));
console.log(singleNumber([4, 1, 2, 1, 2]));
