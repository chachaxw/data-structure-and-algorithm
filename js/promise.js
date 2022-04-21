/*
 * @Author: Chacha
 * @Date: 2022-04-19 22:33:05
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-21 11:49:24
 */

/**
 * Promise 练习
 *
 */
// Promise.all() 方法接收一个 promise 的 iterable 类型（注：Array，Map，Set都属于ES6的iterable类型）的输入，
// 并且只返回一个 Promise 实例， 那个输入的所有 promise 的 resolve 回调的结果是一个数组。
Promise.myAll = (promises) => {
    return new Promise((resolve, reject) => {
        if (!Array.isArray(promises)) {
            return reject("Promise.myAll accepts an array");
        }

        let count = 0;
        let result = [];
        const length = promises.length;

        promises.forEach((p, i) => {
            Promise.resolve(p)
                .then((res) => {
                    count += 1;
                    result[i] = res;

                    if (count === length) {
                        resolve(result);
                    }
                })
                .catch(reject);
        });
    });
};

// 该Promise.allSettled()方法返回一个在所有给定的 promise 都已经 fulfilled 或 rejected 后的 promise，
// 并带有一个对象数组，每个对象表示对应的 promise 结果。
Promise.myAllSettled = (promises) => {
    return new Promise((resolve, reject) => {
        if (!Array.isArray(promises)) {
            return reject("Promise.myAllSettled accepts an array");
        }

        const length = promises.length;
        let result = [];
        let remaining = length;

        if (length === 0) {
            return resolve(length);
        }

        const response = (i, value) => {
            if (value instanceof Promise) {
                value.then(
                    (res) => {
                        response(i, res);
                    },
                    (err) => {
                        result[i] = {
                            status: "rejected",
                            reason: err,
                        };

                        if (--remaining === 0) {
                            resolve(result);
                        }
                    }
                );

                return;
            }

            result[i] = {
                status: "fulfilled",
                value,
            };

            if (--remaining === 0) {
                resolve(result);
            }
        };

        for (let i = 0; i < length; i++) {
            response(i, promises[i]);
        }
    });
};

// Promise.race(iterable) 方法返回一个 promise，一旦迭代器中的某个promise解决或拒绝，返回的 promise 就会解决或拒绝。
Promise.myRace = (promises) => {
    return new Promise((resolve, reject) => {
        promises.forEach((p) => {
            Promise.resolve(p).then(resolve).catch(reject);
        });
    });
};

let p1 = Promise.resolve(1);
let p2 = 2;
let p3 = new Promise((resolve) => {
    setTimeout(resolve, 100, 3);
});
let p4 = Promise.reject("出错啦");

Promise.myAll([p1, p2, p3])
    .then((res) => {
        console.log(res, "res--3");
    })
    .catch((err) => {
        console.log("err", err);
    });

Promise.myAllSettled([p1, p2, p4]).then(console.log);

Promise.myRace([p1, p2, p3]).then(console.log);
