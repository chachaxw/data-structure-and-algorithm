/*
 * @Author: Chacha
 * @Date: 2022-03-29 20:37:15
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-04 20:50:45
 */

/**
 * 来源：https://juejin.cn/post/6844903761949753352
 *
 * EventLoop 事件循环
 * 事件环的运行机制是，先会执行栈中的内容，栈中的内容执行后执行微任务，微任务清空后再执行宏任务，
 * 先取出一个宏任务，再去执行微任务，然后在取宏任务清微任务这样不停的循环。
 *
 * EventLoop 是由JS的宿主环境（浏览器）来实现的
 *
 * 事件循环可以简单的描述为以下四个步骤:
 * 1. 函数入栈，当Stack中执行到异步任务的时候，就将他丢给WebAPIs,接着执行同步任务,直到Stack为空
 * 2. 此期间WebAPIs完成这个事件，把回调函数放入队列中等待执行（微任务放到微任务队列，宏任务放到宏任务队列）
 * 3. 执行栈为空时，Event Loop把微任务队列执行清空
 * 4. 微任务队列清空后，进入宏任务队列，取队列的第一项任务放入Stack(栈）中执行，执行完成后，查看微任务队列是否有任务，
 *    有的话，清空微任务队列。重复4，继续从宏任务中取任务执行，执行完成之后，继续清空微任务，如此反复循环，直至清空所有的任务。
 *
 *
 *             执行栈                                                                    WebAPIs
 *     ┌────────────────────┐                   MacroTask Queue                  ┌────────────────────┐
 *     │                    │  Push  ┌──────────────────────────────────┐        │  setTimeout        │
 *     │                    │<───────│ Callback1  Callback2  Callback3  │<───────│  addEventListener  │
 *     │                 │  │        └──────────────────────────────────┘        │  Ajax              │
 *     │       Call3     │  │                                                    │  onload            │
 *     │                 │  │                                                    │  click             │
 *     │       Call2     │  │                                                    │  setImmediate(IE)  │
 *     │                 │  │                                                    │  MessageChannel    │
 *     │       Call1     │  │                                                    └────────────────────┘
 *     │                 │  │
 *     │       Global    │  │                   MicroTask Queue                  ┌────────────────────┐
 *     │                 v  │        ┌──────────────────────────────────┐        │  promise.then()    │
 *     │                    │───────>│ incoming: connections, data, ... │<───────│  MutationObserver  │
 *     └────────────────────┘        └──────────────────────────────────┘        └────────────────────┘
 *
 *
 * 浏览器中的任务源(task):
 * 1. 宏任务(macrotask):
 *    宿主环境提供的，比如浏览器，ajax、setTimeout、setInterval、setImmediate(只兼容ie)、
 *    script、requestAnimationFrame、messageChannel、UI渲染、一些浏览器api
 * 2. 微任务(microtask)：
 *    语言本身提供的，比如promise.then，then、queueMicrotask(基于then)、mutationObserver(浏览器提供)、messageChannel
 *
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

// NodeJS 和 Chrome 中的执行结果都是：
// script start
// async1 start
// async2
// promise1
// script end
// async1 end
// promise2
// setTimeout

/**
 * Node 环境中的事件循环
 *
 * Node是基于V8引擎的运行在服务端的JavaScript运行环境，在处理高并发、I/O密集(文件操作、网络操作、数据库操作等)场景有明显的优势。
 * 虽然用到也是V8引擎，但由于服务目的和环境不同，导致了它的API与原生JS有些区别，其Event Loop还要处理一些I/O，
 * 比如新的网络连接等，所以Node的Event Loop(事件环机制)与浏览器的是不太一样。
 *
 *
 *             执行栈
 *     ┌────────────────────┐
 * ┌──>│       timers       │
 * │   ├────────────────────│
 * │   ├────────────────────│
 * │   │  pending callbacks │
 * │   ├────────────────────│
 * │   ├────────────────────│
 * │   │    idle, prepare   │
 * │   ├────────────────────│
 * │   ├────────────────────│       ┌──────────────────────────────────┐
 * │   │        poll        │<──────│ incoming: connections, data, ... │
 * │   ├────────────────────│       └──────────────────────────────────┘
 * │   ├────────────────────│
 * │   │        check       │
 * │   ├────────────────────│
 * │   ├────────────────────│
 * └───│   close callbacks  │
 *     └────────────────────┘
 *
 *
 * 执行顺序如下：
 * 1. timers: 计时器，执行 setTimeout 和 setInterval 的回调
 * 2. pending callbacks: 执行延迟到下一个迭代的 I/O 回调
 * 3. idle, prepare: 队列的移动，仅系统内部使用
 * 4. poll轮询: 检索新的 I/O 事件，执行与 I/O 相关的回调。
 *    事实上除了其他几个阶段处理的事情，其他几乎所有的异步都在这个阶段处理。
 * 5. check: 执行 setImmediate 回调，setImmediate 在这里执行
 * 6. close callbacks: 执行 close 事件的 callback，一些关闭的回调函数，如 socket.on('close', ...)
 *
 */

function taskEventLoop() {
    console.log("====================================");
    console.log("Event Loop In Node", process.version);
    console.log("====================================");

    // Timer
    setTimeout(() => {
        console.log("Timer phase");

        process.nextTick(() => {
            console.log("Timer phase - nextTick");
        });

        Promise.resolve().then(() => {
            console.log("Timer phase - promise");
        });
    });

    // Check
    setImmediate(() => {
        console.log("Check phase");

        process.nextTick(() => {
            console.log("Check phase - nextTick");
        });

        Promise.resolve().then(() => {
            console.log("Check phase - promise");
        });
    });

    // Poll
    console.log("Poll phase");

    process.nextTick(() => {
        console.log("Poll phase - nextTick");
    });

    Promise.resolve().then(() => {
        console.log("Poll phase - promise");
    });
}

taskEventLoop();

// ====================================
// Event Loop In Node v16.14.0
// ====================================
// Poll phase
// Poll phase - nextTick
// Poll phase - promise
// Timer phase
// Timer phase - nextTick
// Timer phase - promise
// Check phase
// Check phase - nextTick
// Check phase - promise
