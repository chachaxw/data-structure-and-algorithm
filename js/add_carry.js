/*
 * @Author: Chacha
 * @Date: 2022-03-21 17:23:19
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-22 15:59:04
 */

/**
 * 维基百科：https://zh.wikipedia.org/wiki/柯里化
 *
 * 什么是函数柯里化（curry）?
 * 函数柯里化（curry）是函数式编程里面的概念。是把接受多个参数的函数变换成接受一个单一参数（最初函数的第一个参数）的函数，
 * 并且返回接受余下的参数而且返回结果的新函数的技术。
 * 柯里化其实是一种函数的转换，它是指将一个函数从可调用的 f(a, b, c) 转换为可调用的 f(a)(b)(c)。
 * 柯里化不会调用函数，它只是对函数进行转换。
 *
 * 例如：
 * const foo = (a) => (b) => a*a + b*b;
 *
 * 这样调用上述函数：(foo(3))(4)，或直接foo(3)(4)。
 *
 */

const curry = (func) => {
    const curried = (...args) => {
        if (args.length >= func.length) {
            // 如果传入的 args 长度与原始函数所定义的（func.length）相同或者更长，那么只需要使用 func.apply 将调用传递给它即可。
            return func.apply(this, args);
        } else {
            // 否则，获取一个偏函数：目前还没有调用 func。取而代之的是，返回另一个包装器 pass，
            // 它将重新应用 curried，将之前传入的参数与新的参数一起传入。
            return (...args1) => {
                return curried.apply(this, args.concat(args1));
            };
        }
    };

    return curried;
};

const sum = (a, b, c) => a + b + c;

let curriedSum = curry(sum);

console.log(curriedSum(1, 2, 3)); // 6
console.log(curriedSum(1)(2, 3)); // 6
console.log(curriedSum(1)(2)(3)); // 6
