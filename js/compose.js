/*
 * @Author: Chacha
 * @Date: 2022-03-23 15:31:04
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-23 15:58:48
 */
// 用法如下:
function fn1(x) {
    return x + 1;
}

function fn2(x) {
    return x + 2;
}

function fn3(x) {
    return x + 3;
}

function fn4(x) {
    return x + 4;
}

const a = compose(fn1, fn2, fn3, fn4);

console.log(a(1)); // 1+4+3+2+1=11

function compose(...fn) {
    return fn.reduce(
        (result, it) => {
            return (...args) => result(it(...args));
        },
        (it) => it
    );
}
