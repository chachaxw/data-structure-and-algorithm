/*
 * @Author: Chacha
 * @Date: 2022-03-22 13:46:02
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-22 13:52:51
 */

// Q1: 实现一个非原生类的浅拷贝函数
function shallowCopy(obj) {
    let data = Object.create(null);

    for (const key in obj) {
        if (Object.hasOwnProperty.call(obj, key)) {
            data[key] = obj[key];
        }
    }

    // 将对象 obj 的原型对象设置给 data
    return Object.setPrototypeOf(data, Object.getPrototypeOf(obj));
}

class UserModel {
    firstName;
    lastName;

    constructor(firstName, lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
    }

    fullName() {
        return this.firstName + " " + this.lastName;
    }
}

const user = new UserModel("Hello", "Chacha");
const user2 = shallowCopy(user);

user2.firstName = "Hello 1";
user2.lastName = "Chacha 1";

console.log("====================================");
console.log(user, user2);
console.log("====================================");

console.assert(user2 instanceof UserModel);
console.assert(user.fullName() === "Hello Chacha");
console.assert(user2.fullName() === "Hello 1 Chacha 1");
