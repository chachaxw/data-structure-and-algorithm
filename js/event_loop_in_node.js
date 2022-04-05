/*
 * @Author: Chacha
 * @Date: 2022-04-04 21:58:32
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-04 22:15:51
 */

/**
 *
 * Event Loop 在 Node 中的测试用例
 *
 */

console.log("1");

setTimeout(function () {
    console.log("2");

    process.nextTick(function () {
        console.log("3");
    });

    new Promise(function (resolve) {
        console.log("4");
        resolve();
    }).then(function () {
        console.log("5");
    });
});

process.nextTick(function () {
    console.log("6");
});

new Promise(function (resolve) {
    console.log("7");
    resolve();
}).then(function () {
    console.log("8");
});

setTimeout(function () {
    console.log("9");

    process.nextTick(function () {
        console.log("10");
    });

    new Promise(function (resolve) {
        console.log("11");
        resolve();
    }).then(function () {
        console.log("12");
    });
});

console.log("13");

// 1->7->13->6->8->2->4->3->5->9->11->10->12
