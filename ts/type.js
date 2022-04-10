/*
 * @Author: Chacha
 * @Date: 2022-04-10 14:35:33
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-10 15:08:36
 */
/**
 * Typescript常见类型
 *
 */
/**
 * Unknown
 * 是不可预先定义的类型，在多数情况下，它用于代替 any 的功能同时保留静态检查的能力。
 * 在静态编译的时候，unknown 不能调用任何方法，而 any 可以。
 *
 */
const num = 10;
num.split(""); // 这里和 any 一样完全用于通过静态检查
const str = "hello world";
// str.split(" "); // Error: 静态检查不通过报错
// unknown 的一个使用场景，避免使用 any 作为函数的参数类型而导致的静态类型检查 bug
function testUnknown(params) {
    if (Array.isArray(params)) {
        return params.length; // Pass: 这个代码块中，类型守卫已经将 params 识别为 Array 类型
    }
    // return params.length; // Error: 这里的 params 为 unknown 类型，静态检查报错，如果入参是 any 类型，则会放弃类型检查，直接成功，带来报错风险。
    throw new Error("Params type is unknown");
}
/**
 * Enum
 * TypeScript支持数字的和基于字符串的枚举。
 *
 */
// 数字枚举
// 如上，我们定义了一个数字枚举， Up使用初始化为 1。 其余的成员会从 1开始自动增长。
// 换句话说， Direction.Up的值为 1， Down为 2， Left为 3， Right为 4。
var Direction;
(function (Direction) {
    Direction[Direction["Up"] = 1] = "Up";
    Direction[Direction["Down"] = 2] = "Down";
    Direction[Direction["Left"] = 3] = "Left";
    Direction[Direction["Right"] = 4] = "Right";
})(Direction || (Direction = {}));
// 字符串枚举
// 在一个字符串枚举里，每个成员都必须用字符串字面量，或另外一个字符串枚举成员进行初始化。
var Direction1;
(function (Direction1) {
    Direction1["Up"] = "UP";
    Direction1["Down"] = "DOWN";
    Direction1["Left"] = "LEFT";
    Direction1["Right"] = "RIGHT";
})(Direction1 || (Direction1 = {}));
// 计算成员和常量成员
var FileAccess;
(function (FileAccess) {
    // constant members
    FileAccess[FileAccess["None"] = 0] = "None";
    FileAccess[FileAccess["Read"] = 2] = "Read";
    FileAccess[FileAccess["Write"] = 4] = "Write";
    FileAccess[FileAccess["ReadWrite"] = 6] = "ReadWrite";
    // computed member
    FileAccess[FileAccess["G"] = "123".length] = "G";
})(FileAccess || (FileAccess = {}));
/**
 * void
 * 在 Typescript 中，void 与 undefined 功能很类似，用于在逻辑上避免不经意使用了空指针导致的错误。
 * void 和 undefined 类型最大的区别是: undefined 是 void 的子集，当你对函数的返回值并不在意时，使用 void 而不是 undefined。
 */
