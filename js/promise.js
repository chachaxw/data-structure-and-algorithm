/*
 * @Author: Chacha
 * @Date: 2022-04-19 22:33:05
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-20 23:28:20
 */

/**
 * Promise 练习
 *
 */

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
