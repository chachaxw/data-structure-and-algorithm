/*
 * @Author: Chacha
 * @Date: 2022-03-28 00:00:28
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-28 10:02:11
 */

/**
 *
 * @param {*} obj 实例对象
 * @param {*} func 构造函数
 * @returns true false
 */
const instanceOf1 = (obj, func) => {
    if (!(obj && ["object", "function"].includes(typeof obj))) {
        return false;
    }

    let proto = Object.getPrototypeOf(obj);

    if (proto === func.prototype) {
        return true;
    } else if (proto === null) {
        return false;
    } else {
        return instanceOf1(proto, func);
    }
};
/**
 *
 * @param {*} obj 实例对象
 * @param {*} func 构造函数
 * @returns true false
 */
const instanceOf2 = (obj, func) => {
    if (!(obj && ["object", "function"].includes(typeof obj))) {
        return false;
    }

    let proto = obj;

    while ((proto = Object.getPrototypeOf(proto))) {
        if (proto === null) {
            return false;
        } else if (proto === func.prototype) {
            return true;
        }
    }

    return false;

    // while (true) {
    //   if (proto === null) {
    //     return false
    //   } else if (proto === func.prototype) {
    //     return true
    //   } else {
    //     proto = Object.getPrototypeOf(proto)
    //   }
    // }
};

let Fn = function () {};
let p1 = new Fn();

console.log(instanceOf1({}, Object)); // true
console.log(instanceOf1(p1, Fn)); // true
console.log(instanceOf1({}, Fn)); // false
console.log(instanceOf1(null, Fn)); // false
console.log(instanceOf1(1, Fn)); // false
console.log(instanceOf1(function a() {}, Function)); // true

console.log("-----------------------");

console.log(instanceOf2({}, Object)); // true
console.log(instanceOf2(p1, Fn)); // true
console.log(instanceOf2({}, Fn)); // false
console.log(instanceOf2(null, Fn)); // false
console.log(instanceOf2(1, Fn)); // false
console.log(instanceOf1(function a() {}, Function)); // true
