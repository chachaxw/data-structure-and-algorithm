/*
 * @Author: Chacha
 * @Date: 2022-03-28 12:36:33
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-28 23:15:45
 */

/**
 * Reflect
 * ES6 提供了一个全新的 API-Reflect，Reflect 和 Proxy 是相对的，我们可以用 Reflect 操作对象。
 *
 * Reflect 存在的意义
 * 1. 将 Object 对象一些内部的方法，放到 Reflect 对象上。比如 Object.defineProperty
 *    也就是说，从 Reflect 对象上可以拿到语言内部的方法。
 *
 * 2. 操作对象时出现报错返回 false
 *    Object.defineProperty(obj,name,desc) 在无法定义属性时，会抛出一个错误，
 *    而Reflect.defineProperty(obj,name,desc)则会返回 false,这样会更合理一些。
 *
 *    // 旧写法
 *    try {
 *      Object.defineProperty(target, property, attributes);
 *    } catch (err) {
 *      //failure
 *    }
 *   // 新写法
 *   if (Reflect.defineProperty(target, property, attributes)) {
 *     //success
 *   } else {
 *     //failure
 *   }
 *
 * 3. 让操作对象的编程变为函数式编程
 *    // 老写法
 *    "assign" in Object; // true
 *
 *    // 新写法
 *    Reflect.has(Object, "assign"); // true
 *
 * 4. 保持和 Proxy 对象的方法一一对应
 *    Reflect 对象的方法与 Proxy 对象的方法一一对应，只要是 Proxy 对象的方法，就能在 Reflect 对象上找到对应的方法。
 *
 *    Proxy(target, {
 *      set: function (target, name, value, receiver) {
 *        var success = Reflect.set(target, name, value, receiver);
 *        if (success) {
 *          console.log("property" + name + "on" + target + "set do " + value);
 *        }
 *        return success;
 *      },
 *    });
 *
 * Reflect 常用 API
 * Reflect 一共有 13 个静态方法：
 * 1. Reflect.defineProperty(target, name, desc) 与 Object.defineProperty(target, name, desc)类似，
 *    当时对象无法定义时，Object.defineProperty 会报错，而 Reflect.defineProperty 不会，
 *    它会返回 false，成功时返回 true，如果不是对象还是会报错。
 * 2. Reflect.getPrototypeOf(target) 与 Object.getPrototypeOf 一样，返回指定的对象的原型。
 * 3. Reflect.setProtoTypeOf(target, prototype) 和 Object.setPrototypeOf(target, prototype) 一样，
 *    它将指定对象的原型设置为另一个对象。
 * 4. Reflect.getOwnPropertyDescriptor(target, name)和 Object.getOwnPropertyDescriptor(target, name) 一样，
 *    如果在对象中存在，则返回给定的属性的属性描述符。
 * 5. Reflect.isExtensible(target) 与 Object.isExtensible(target) 类似，判断一个对象是否可扩展(是否可以在它上面添加新的属性)，
 *    它们的不同点是，当参数不是对象时(原始值),Object 将它强制转换为一个对象，Reflect 直接报错。
 * 6. Reflect.preventExtensions(target) 与 Object.preventExtensions(target) 类似，阻止新属性添加到对象，不同点和上一条一样。
 * 7. Reflect.apply(target, thisArg, args) 与 Function.prototype.apply.call(fn, obj, args) 一样。
 * 8. Reflect.ownKeys(target) 与 Object.getOwnPropertyNames(target).concat(Object.getOwnPropertySymbols(target)) 一样，
 *    返回一个包含所有自身属性(不包含继承属性)的数组。
 * 9. Reflect.has(target,name) 与 in 操作符一样，让判断操作都变成函数行为。
 * 10. Reflect.deleteProperty(target,name) 与 delete 操作符一样，让删除操作变成函数行为，返回布尔值代表成功或者失败。
 * 11. Reflect.construct(target,args[,newTarget]) 与 new 操作符一样，target 构造函数，
 *     第二参数是构造函数的参数类数组，第三个是 new.target 的值。
 * 12. Reflect.get(target, name[,receiver]) 与 Obj[key] 一样，第三个参数是当要取值的 key 部署了 getter 时，
 *     访问其函数的 this 绑定为 receiver 对象。
 * 13. Reflect.set(target, name, value[,receiver]) 设置 target 对象的 key 属性等于 value，第三个参数和 set 一样。返回一个布尔值。
 *
 */

let myObj = {
    name: "Reflect API",
    hello: "hello",
    chacha: "chacha",
};

console.log("====================================");
console.log("旧写法", "assign" in Object); // true
console.log("新写法", Reflect.has(Object, "assign")); // true
console.log("====================================");

console.log("====================================");
console.log(
    "旧写法",
    Function.prototype.apply.call(Math.floor, undefined, [1.75])
); // 1
console.log("新写法", Reflect.apply(Math.floor, undefined, [1.75])); // true
console.log("====================================");
console.log("====================================");
console.log("旧写法", delete myObj.hello); // true
console.log("新写法", Reflect.deleteProperty(myObj, "chacha")); // true
console.log("myObj", myObj); // { name: 'Reflect API' }
console.log("====================================");

class Greeting {
    constructor(name) {
        this.name = name;
    }
}
// new 的写法
const instance = new Greeting("张三");
// Reflect.construct 的写法
const instance1 = Reflect.construct(Greeting, ["张三"]);
console.log("====================================");
console.log("instance", instance, "instance1", instance1);
console.log("====================================");

// 旧写法
Object.defineProperty(instance, "now", {
    value: () => Date.now(),
});
Reflect.defineProperty(instance1, "now", {
    value: () => Date.now(),
});
console.log("====================================");
console.log("instance", instance, "instance1", instance1);
console.log("====================================");

// Reflect.get(1, "foo"); // 报错
// Reflect.get(false, "foo"); // 报错
// Reflect.set(1, "foo", {}); // 报错
// Reflect.set(false, "foo", {}); // 报错

var myObject = {
    foo: 1,
    bar: 2,
    get baz() {
        return this.foo + this.bar;
    },
};

var myReceiverObject = {
    foo: 4,
    bar: 4,
};

console.log("====================================");
console.log(Reflect.get(myObject, "baz", myReceiverObject));
console.log("===================================="); // 8

// ES6 为 new 命令引入了一个new.target属性，该属性一般用在构造函数之中，返回 new 命令作用于的那个构造函数。
// 如果构造函数不是通过 new 命令或 Reflect.construct() 调用的，new.target 会返回 undefined，
// 因此这个属性可以用来确定构造函数是怎么调用的。
function Person(name) {
    if (new.target === Person) {
        this.name = name;
    } else {
        throw new Error("必须使用 new 命令生成实例");
    }
}
