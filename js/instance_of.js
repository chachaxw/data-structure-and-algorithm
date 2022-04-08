/*
 * @Author: Chacha
 * @Date: 2022-03-28 00:00:28
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-07 18:19:32
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

    // 获取对象的原型 prototype
    let proto = Object.getPrototypeOf(obj);

    if (proto === func.prototype) {
        // 如果原型 proto 与 func 的原型一致，就说明 obj 是 func 的实例对象，返回 true。
        return true;
    } else if (proto === null) {
        // 如果 proto 等于 null，返回 false。
        return false;
    } else {
        // 否则，继续向上查找原型的原型
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
