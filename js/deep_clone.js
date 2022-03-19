/*
 * @Author: Chacha
 * @Date: 2022-03-18 14:25:08
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-18 17:32:33
 */

/**
 * 来源：https://cloud.tencent.com/developer/article/1497418
 *
 * JS实现深拷贝
 */

// 可以继续遍历的数据类型
const mapTag = "[object Map]";
const setTag = "[object Set]";
const arrayTag = "[object Array]";
const objectTag = "[object Object]";
const argsTag = "[object Arguments]";

// 不可以继续遍历的数据类型
const boolTag = "[object Boolean]";
const dateTag = "[object Date]";
const errorTag = "[object Error]";
const numberTag = "[object Number]";
const regexpTag = "[object RegExp]";
const stringTag = "[object String]";
const symbolTag = "[object Symbol]";
const funcTag = "[object Function]";

const deepTags = [mapTag, setTag, arrayTag, objectTag, argsTag];

// 获取数据类型
function getType(target) {
    return Object.prototype.toString.call(target);
}

// 判断是否是对象
function isObject(target) {
    const type = typeof target;
    return target !== null && (type === "object" || type === "function");
}

// while 循环遍历
function forEach(array, iteratee) {
    let index = -1;
    const length = array.length;

    while (++index < length) {
        iteratee(array[index], index);
    }

    return array;
}

// 初始化被克隆对象的构造函数
function getConstructor(target) {
    return new target.constructor();
}

// 克隆 Symbol
function cloneSymbol(target) {
    return Object(Symbol.prototype.valueOf.call(target));
}

// 克隆 RegExp
function cloneReg(target) {
    const reFlags = /\w*$/;
    const result = new target.constructor(target.source, reFlags.exec(target));
    result.lastIndex = target.lastIndex;
    return result;
}

// 克隆 Function
function cloneFunc(func) {
    const paramReg = /(?<=\().+(?=\)\s+{)/;
    const bodyReg = /(?<=\{)(.|\n)+(?=})/m;
    const funcStr = func.toString();

    if (func.prototype) {
        const param = paramReg.exec(funcStr);
        const body = bodyReg.exec(funcStr);

        // 如果匹配到函数体
        if (body) {
            // console.log("匹配到函数体：", body);

            if (param) {
                // console.log("匹配到参数：", param);

                const paramArr = param[0].split(",");
                return new Function(...paramArr, body[0]);
            } else {
                return new Function(body[0]);
            }
        } else {
            return null;
        }
    } else {
        return eval(funcStr);
    }
}

// 克隆其他数据类型
function cloneOtherType(target, type) {
    const Construct = target.constructor;
    switch (type) {
        case boolTag:
        case dateTag:
        case errorTag:
        case numberTag:
        case stringTag:
            return new Construct(target);
        case regexpTag:
            return cloneReg(target);
        case symbolTag:
            return cloneSymbol(target);
        case funcTag:
            return cloneFunc(target);

        default:
            return null;
    }
}

/**
 *
 * 深度拷贝
 *
 * @param {any} target
 * @param {WeakMap} map
 * @returns
 */
function deepClone(target, map = new WeakMap()) {
    // 如果数据是原始类型，则直接返回数据
    if (!isObject(target)) return target;

    const type = getType(target);
    let cloneTarget;

    if (deepTags.includes(type)) {
        cloneTarget = getConstructor(target);
    } else {
        return cloneOtherType(target, type);
    }

    // 防止循环引用
    if (map.get(target)) {
        return target;
    }
    map.set(target, cloneTarget);

    // 处理 Set 数据类型
    if (type === setTag) {
        target.forEach((val) => {
            cloneTarget.add(deepClone(val));
        });
        return cloneTarget;
    }

    // 处理 Map 数据类型
    if (type === mapTag) {
        target.forEach((key, val) => {
            cloneTarget.set(key, deepClone(val));
        });
        return cloneTarget;
    }

    // 处理数组和对象类型
    const keys = type === arrayTag ? undefined : Object.keys(target);

    forEach(keys || target, (value, key) => {
        if (keys) {
            key = value;
        }
        cloneTarget[key] = deepClone(target[key], map);
    });

    return cloneTarget;
}

// 测试用例
const map = new Map();
const set = new Set();

map.set("Chacha", "Hello World");

set.add("Chacha");
set.add("Hello World");

const target = {
    field1: 1,
    field2: undefined,
    field3: {
        child: "child",
    },
    field4: [2, 4, 8],
    empty: null,
    map,
    set,
    bool: new Boolean(true),
    num: new Number(2),
    str: new String(2),
    symbol: Object(Symbol(1)),
    date: new Date(),
    reg: /\d+/,
    error: new Error(),
    func1: () => {
        console.log("Hello World");
    },
    func2: function (a, b) {
        return a + b;
    },
};

const clonedTarget = deepClone(target);

console.log("====================================");
console.log("克隆之后的对象", clonedTarget);
console.log("====================================");
