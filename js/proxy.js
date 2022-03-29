/*
 * @Author: Chacha
 * @Date: 2022-03-28 23:19:39
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-28 23:36:05
 */

/**
 * Proxy
 * Proxy 对象用于定义基本操作的自定义行为（如属性查找，赋值，枚举，函数调用等），
 * 等同于在语言层面做出修改，所以属于一种“元编程”（meta programming），即对编程语言进行编程。
 *
 * Proxy 就像在目标对象之间的一个代理，任何对目标的操作都要经过代理。代理就可以对外界的操作进行过滤和改写。
 *
 * Proxy 是构造函数，它有两个参数 target 和 handler。
 * target是用 Proxy 包装的目标对象（可以是任何类型的对象，包括原生数组，函数，甚至另一个代理）。
 * handler 是一个对象，其属性是当执行一个操作时定义代理的行为函数。
 *
 * Proxy 只有一个静态方法revocable(target, handler)可以用来创建一个可撤销的代理对象。
 * 两个参数和构造函数的相同。它返回一个包含了所生成的代理对象本身以及该代理对象的撤销方法的对象。
 *
 * 一旦某个代理对象被撤销，它将变的几乎完全不可用，在它身上执行任何的可代理操作都会抛出 TypeError 异常
 * （注意，可代理操作一共有 14 种，执行这 14 种操作以外的操作不会抛出异常）。
 * 一旦被撤销，这个代理对象永远不可能恢复到原来的状态，同时和它关联的目标对象以及处理器对象将有可能被垃圾回收掉。
 * 调用撤销方法多次将不会有任何效果，当然，也不会报错。
 *
 */
const obj = new Proxy(
    {},
    {
        get: function (target, key, receiver) {
            console.log("====================================");
            console.log("Getting key: ", key);
            console.log("====================================");
            return Reflect.get(target, key, receiver);
        },

        set: function (target, key, value, receiver) {
            console.log("====================================");
            console.log("Setting key: ", key);
            console.log("====================================");
            return Reflect.set(target, key, value, receiver);
        },
    }
);

obj.count = 1;
obj.count++;

console.log("====================================");
console.log("obj", obj);
console.log("====================================");

const revocable = Proxy.revocable(
    {},
    {
        get(target, name) {
            return "[[" + name + "]]";
        },
    }
);
// revocable => {"proxy":proxy,"revoke":revoke}

const proxy = revocable.proxy;
proxy.foo; // "[[foo]]"

console.log("====================================");
console.log("proxy", proxy, proxy.foo);
console.log("====================================");

revocable.revoke(); // 执行撤销方法

// proxy.foo; // TypeError: Cannot perform 'get' on a proxy that has been revoked
// proxy.foo = 1; // TypeError: Cannot perform 'get' on a proxy that has been revoked
// delete proxy.foo; // TypeError: Cannot perform 'get' on a proxy that has been revoked
console.log(typeof proxy); // "object" 因为typeof 不属于代理操作
