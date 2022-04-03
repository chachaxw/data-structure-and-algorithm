/*
 * @Author: Chacha
 * @Date: 2022-03-29 20:37:15
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-30 22:12:18
 */

/**
 * EventLoop 事件循环
 * 事件环的运行机制是，先会执行栈中的内容，栈中的内容执行后执行微任务，微任务清空后再执行宏任务，
 * 先取出一个宏任务，再去执行微任务，然后在取宏任务清微任务这样不停的循环。
 *
 * EventLoop 是由JS的宿主环境（浏览器）来实现的；
 *
 * 事件循环可以简单的描述为以下四个步骤:
 * 1. 函数入栈，当Stack中执行到异步任务的时候，就将他丢给WebAPIs,接着执行同步任务,直到Stack为空
 * 2. 此期间WebAPIs完成这个事件，把回调函数放入队列中等待执行（微任务放到微任务队列，宏任务放到宏任务队列）
 * 3. 执行栈为空时，Event Loop把微任务队列执行清空
 * 4. 微任务队列清空后，进入宏任务队列，取队列的第一项任务放入Stack(栈）中执行，执行完成后，查看微任务队列是否有任务，
 *    有的话，清空微任务队列。重复4，继续从宏任务中取任务执行，执行完成之后，继续清空微任务，如此反复循环，直至清空所有的任务。
 *
 *
 * 浏览器中的任务源(task):
 * 1. 宏任务(macrotask):
 *    宿主环境提供的，比如浏览器，ajax、setTimeout、setInterval、setTmmediate(只兼容ie)、
 *    script、requestAnimationFrame、messageChannel、UI渲染、一些浏览器api
 * 2. 微任务(microtask)：
 *    语言本身提供的，比如promise.then，then、queueMicrotask(基于then)、mutationObserver(浏览器提供)、messageChannel
 *
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

// script start
// async1 start
// async2
// promise1
// script end
// async1 end
// promise2
// setTimeout
