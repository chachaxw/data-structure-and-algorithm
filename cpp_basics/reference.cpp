/*
 * @Author: Chacha
 * @Date: 2022-02-24 15:41:15
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-02-24 16:14:03
 */

/**
 * 来源: https://www.runoob.com/cplusplus/cpp-references.html
 *
 * C++ 引用
 * 引用变量是一个别名，也就是说，它是某个已存在变量的另一个名字。一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量。
 *
 * C++ 引用 vs 指针
 * 引用和指针三个主要的不同：
 * 1. 不存在空引用。引用必须连接到一块合法的内存。
 * 2. 一旦引用被初始化为一个对象，就不能被指向到另一个对象，指针可以在任何时候指向到另一个对象。
 * 3. 引用必须在创建时被初始化。指针可以在任何时候被初始化。
 *
 * 把引用作为返回值
 * 当返回一个引用时，要注意被引用的对象不能超出作用域。所以返回一个对局部变量的引用是不合法的，但是，可以返回一个对静态变量的引用。
 *
 */

// C++ 引用的使用
#include <iostream>

using namespace std;

int &func()
{
    int q;
    //! return q; // 在编译时发生错误
    static int x;
    return x; // 安全，x 在函数作用域外依然是有效的
}

int main(int argc, char const *argv[])
{
    // 声明简单的变量
    int i;
    double d;

    // 声明引用变量
    int &r = i;    // r 是一个初始化为 i 的 int 型引用
    double &s = d; // s 是一个初始化为 d 的 double 型引用

    i = 5;

    cout << "i 的值: " << i << endl;
    cout << "i 的引用 r 的值: " << r << endl;

    d = 9.9;

    cout << "d 的值: " << d << endl;
    cout << "d 的引用 s 的值: " << s << endl;

    return 0;
}
