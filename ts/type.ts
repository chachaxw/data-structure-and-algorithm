/*
 * @Author: Chacha
 * @Date: 2022-04-10 14:35:33
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-10 15:32:05
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
const num: number = 10;
(num as unknown as string).split(""); // 这里和 any 一样完全用于通过静态检查

const str: unknown = "hello world";
// str.split(" "); // Error: 静态检查不通过报错

// unknown 的一个使用场景，避免使用 any 作为函数的参数类型而导致的静态类型检查 bug
function testUnknown(params: unknown): number {
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
enum Direction {
    Up = 1,
    Down,
    Left,
    Right,
}

// 字符串枚举
// 在一个字符串枚举里，每个成员都必须用字符串字面量，或另外一个字符串枚举成员进行初始化。
enum Direction1 {
    Up = "UP",
    Down = "DOWN",
    Left = "LEFT",
    Right = "RIGHT",
}

// 计算成员和常量成员
enum FileAccess {
    // constant members
    None,
    Read = 1 << 1,
    Write = 1 << 2,
    ReadWrite = Read | Write,
    // computed member
    G = "123".length,
}

/**
 * void
 * 在 Typescript 中，void 与 undefined 功能很类似，用于在逻辑上避免不经意使用了空指针导致的错误。
 * void 和 undefined 类型最大的区别是: undefined 是 void 的子集，当你对函数的返回值并不在意时，使用 void 而不是 undefined。
 *
 */

/**
 * Tuple
 * 元组(Tuple)表示一个已知数量和类型的数组，可以理解它是一种特殊的数组。
 *
 */
const tuple: [string, number] = ["Hello", 1];

/**
 * never
 * never 类型是没法正常结束返回的类型，一个必定会报错或死循环的函数会返回这样的类型。
 *
 */
function testNever(): never {
    throw new Error("testNever return never type");
}
function testNever1(): never {
    while (true) {}
}

// 任何类型联合上 never 类型，还是原来的类型
type language = "TS" | never;
