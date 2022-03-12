/*
 * @Author: Chacha
 * @Date: 2022-03-12 18:58:03
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-12 19:00:03
 */

/**
 * 说明：简单实现一个事件订阅机制，具有监听on和触发emit方法， off取消绑定
 * 示例：
 * const event = new EventEmitter();
 * event.on('someEvent', (...args) => {
 *     console.log('some_event triggered', ...args);
 * });
 * event.emit('someEvent', 'abc', '123');
 */

function EventEmitter() {}

/* 功能实现 */
EventEmitter.prototype.on = function (eventName, callback) {
    if (!this.handles) {
        this.handles = {};
    }

    if (!this.handles[eventName]) {
        this.handles[eventName] = [];
    }

    this.handles[eventName].push(callback);
};

EventEmitter.prototype.emit = function (eventName, ...args) {
    if (!this.handles[eventName]) {
        return;
    }

    this.handles[eventName].forEach(function (callback) {
        callback(...args);
    });
};

EventEmitter.prototype.off = function (eventName) {
    if (!this.handles[eventName]) {
        return;
    }

    this.handles[eventName] = [];
};

const eventEmitter = new EventEmitter();

eventEmitter.on("someEvent1", (...args) => {
    console.log("触发了 someEvent1 事件1", ...args);
});

eventEmitter.on("someEvent2", (...args) => {
    console.log("触发了 someEvent2 事件2", ...args);
});

eventEmitter.emit("someEvent1", "abcd");
eventEmitter.emit("someEvent2", "1234");
