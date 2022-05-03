/*
 * @Author: Chacha
 * @Date: 2022-05-03 12:20:57
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-05-03 12:21:37
 */

// 适合纯11位手机
const splitMobile = (mobile, format = "-") => {
    return String(mobile).replace(/(?=(\d{4})+$)/g, format);
};
// 适合11位以内的分割
const splitMobile2 = (mobile, format = "-") => {
    return String(mobile)
        .replace(/(?<=(\d{3}))/, format)
        .replace(/(?<=([\d\-]{8}))/, format);
};

console.log(splitMobile(13798247501));
console.log(splitMobile2(13798247501));
