/*
 * @Author: Chacha
 * @Date: 2022-04-08 11:53:02
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-08 12:08:52
 */

/**
 *
 * Generator
 *
 */

function* generator() {
    yield "status one";
    yield "status two";
    return "hello world";
}

const iterator = generator(); // 调用 Generator函数，函数并没有执行，返回的是一个Iterator对象

console.log("Iterator对象", iterator);

for (let value of iterator) {
    console.log(value);
}

console.log("====================================");

console.log(iterator.next()); // { value: "status one", done: false }，value 表示返回值，done 表示遍历还没有结束
console.log(iterator.next()); // { value: "status two", done: false }
console.log(iterator.next()); // { value: "status one", done: true }
