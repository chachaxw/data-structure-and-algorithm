/*
 * @Author: Chacha
 * @Date: 2022-03-22 14:22:09
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-22 19:25:37
 */

// 实现一个异步任务执行器, 其最多只能同时执行 capacity 个异步任务,
// 若同时执行任务数达到 capacity, 则需要等待已有任务完成后才能被执行.

class AsyncWorker {
    constructor(capacity) {
        this.capacity = capacity; // 任务最大并发数量
        this.queue = []; // 任务队列
        this.processTasks = []; // 正在执行的任务队列
    }

    /**
     * @param {() => T | Promise<T>} task
     * @returns Promise<T>
     */
    exec(task) {
        this.queue.push(task);
        return new Promise((resolve, reject) => {
            this.run(resolve, reject);
        });
    }

    run(resolve, reject) {
        while (this.processTasks.length <= this.capacity && this.queue.length) {
            const task = this.queue.shift();
            const promise = task()
                .then((val) => {
                    // 任务执行完毕，就移除该任务，并准备执行下一个任务。
                    this.processTasks.splice(
                        this.processTasks.indexOf(promise),
                        1
                    );
                    this.run(resolve, reject);
                    resolve(val);
                })
                .catch((error) => reject(error));

            this.processTasks.push(promise);
        }
    }
}

async function testAsyncWorker() {
    const start = Date.now();
    const createTask = (timeout, error) => {
        return () =>
            new Promise((resolve, reject) => {
                setTimeout(() => {
                    const realCost = Date.now() - start;
                    const idealCost = (realCost - (realCost % 100)) | 0;

                    console.log(
                        `TASK DONE, timeout: ${timeout}, cost: ${idealCost}`
                    );

                    if (error) reject(error);
                    else resolve(timeout);
                }, timeout);
            });
    };

    const worker = new AsyncWorker(2);

    await Promise.allSettled([
        worker.exec(createTask(100)),
        worker.exec(createTask(201)),
        worker.exec(createTask(202, "FAKE ERROR")),
        worker.exec(createTask(203)),
        worker.exec(createTask(300)),
    ]);

    const r = await worker.exec(createTask(100));
    console.log("RETURN", r);

    // 期望控制台得到以下输出:
    // TASK DONE, timeout: 100, cost: 100
    // TASK DONE, timeout: 201, cost: 200
    // TASK DONE, timeout: 202, cost: 300
    // TASK DONE, timeout: 203, cost: 400
    // TASK DONE, timeout: 300, cost: 600
    // TASK DONE, timeout: 100, cost: 700
    // RETURN 100
}

testAsyncWorker();
