/*
 * @Author: Chacha
 * @Date: 2022-04-02 19:38:45
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-02 19:51:36
 */

/**
 *
 * 实现一个randomString函数，返回一个数组， 该数组内有一千个字符串， 每串字符串为6位数0-9的随机验证码，不可重复?
 *
 */

const randomString = (length) => {
    let data = [];
    let map = {};

    for (let i = 0; i < length; i++) {
        let num = Math.random().toString().slice(2, 8);

        while (map[num]) {
            // 当 map 里面存在当前字符串时，重新赋值 num
            num = Math.random().toString().slice(2, 8);
        }

        // 将随机字符串存入 map 中，方便后续判断该字符串是否存在
        map[num] = true;
        data.push(num);
    }

    return data;
};

const result = randomString(10);
console.log(result);
