/*
 * @Author: Chacha
 * @Date: 2022-04-04 21:18:16
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-04 22:39:58
 */

/**
 *
 * Event Loop 在浏览器中的测试用例
 *
 */
console.log("1");

setTimeout(function () {
    console.log("2");
    new Promise(function (resolve) {
        console.log("3");
        resolve();
    }).then(function () {
        console.log("4");
    });
    setTimeout(function () {
        console.log("5");
        new Promise(function (resolve) {
            console.log("6");
            resolve();
        }).then(function () {
            console.log("7");
        });
    });
    console.log("14");
});

new Promise(function (resolve) {
    console.log("8");
    resolve();
}).then(function () {
    console.log("9");
});

setTimeout(function () {
    console.log("10");
    new Promise(function (resolve) {
        console.log("11");
        resolve();
    }).then(function () {
        console.log("12");
    });
});

console.log("13");

// 1->8->13->9->2->3->14->4->10->11->12->5->6->7
