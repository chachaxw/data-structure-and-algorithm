/*
 * @Author: Chacha
 * @Date: 2022-03-11 16:31:46
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-12 19:11:49
 */

/**
 * JavaScript之 new 的模拟实现
 *
 * new 运算符创建一个用户定义的对象类型的实例或具有构造函数的内置对象类型之一
 *
 */

function objectFactory() {
    var constructor = Array.prototype.shift.call(arguments); // 取出第一个参数，就是我们要传入的构造函数
    var obj = Object.create(constructor.prototype); // 根据构造函数的原型创建一个对象
    var result = constructor.apply(obj, arguments);

    return typeof result === "object" && result !== null ? result : obj;
}

function Test(name, age) {
    this.name = name;
    this.age = age;
    this.habit = "Games";
}

Test.prototype.height = 177;

Test.prototype.sayYourName = function () {
    console.log("I am " + this.name);
};

let person = objectFactory(Test, "Chacha", "28");

console.log(person.name); // Chacha
console.log(person.habit); // Games
console.log(person.height); // 177

person.sayYourName();
