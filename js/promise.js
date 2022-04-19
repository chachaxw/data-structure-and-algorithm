/*
 * @Author: Chacha
 * @Date: 2022-04-19 22:33:05
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-19 22:40:07
 */

/**
 * Promise 练习
 *
 */

Promise.myAll = (promises) => {
    return new Promise((resolve, reject) => {
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

let p1 = Promise.resolve(1);
let p2 = 2;
let p3 = new Promise((resolve) => {
    setTimeout(resolve, 100, 3);
});
// let p4 = Promise.reject("出错啦");

Promise.myAll([p1, p2, p3])
    .then((res) => {
        console.log(res, "res--3");
    })
    .catch((err) => {
        console.log("err", err);
    });
