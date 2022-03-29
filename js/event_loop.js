/*
 * @Author: Chacha
 * @Date: 2022-03-29 20:37:15
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-29 20:43:56
 */

async function async1() {
    console.log("async1 start");
    await async2();
    console.log("async1 end");
}

async function async2() {
    console.log("async2");
}

console.log("script start");

setTimeout(() => {
    console.log("setTimeout");
}, 0);

async1();

new Promise((resolve) => {
    console.log("promise1");
    resolve();
}).then(() => console.log("promise2"));

console.log("script end");
