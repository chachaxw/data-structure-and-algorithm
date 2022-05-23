/*
 * @Author: Chacha
 * @Date: 2022-05-23 23:33:55
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-05-23 23:34:16
 */

const simulateSetInterval = (func, timeout) => {
    let timer = null;

    const interval = () => {
        timer = setTimeout(() => {
            func();
            interval();
        }, timeout);
    };

    interval();

    return () => clearTimeout(timer);
};

const cancel = simulateSetInterval(() => {
    console.log(1);
}, 300);

setTimeout(() => {
    cancel();
}, 1000);
