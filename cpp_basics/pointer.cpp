/*
 * @Author: Chacha
 * @Date: 2022-02-24 14:28:15
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-02-25 14:38:54
 */

/**
 * 来源：https://www.runoob.com/cplusplus/cpp-pointers.html
 *
 * 什么是指针？
 * 指针是一个变量，其值为另一个变量地址，即内存位置的直接地址。就像其他变量或常量一样，您必须在使用指针存储其他变量地址之前，
 * 对其进行声明。指针变量的一般形式为:
 * type *var-name;
 *
 * type 是指针的基类型，它必须是一个有效的 C++ 数据类型，var-name 是指针变量的名称。
 * 用来声明指针的星号 * 与乘法中使用的星号是相同的。但是，在这个语句中，星号是用来指定一个变量是指针。
 * 以下是有效的指针声明：
 * int    *ip;    // 一个整型的指针
 * double *dp;    // 一个 double 型的指针
 * float  *fp;    // 一个浮点型的指针
 * char   *ch;    // 一个字符型的指针
 *
 * 所有指针的值的实际数据类型，不管是整型、浮点型、字符型，还是其他的数据类型，都是一样的，
 * 都是一个代表内存地址的长的十六进制数。不同数据类型的指针之间唯一的不同是，指针所指向的变量或常量的数据类型不同。
 *
 * Null指针
 * 在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯。赋为 NULL 值的指针被称为空指针。
 * NULL 指针是一个定义在标准库中的值为零的常量。
 * 在大多数的操作系统上，程序不允许访问地址为 0 的内存，因为该内存是操作系统保留的。然而，内存地址 0 有特别重要的意义，
 * 它表明该指针不指向一个可访问的内存位置。但按照惯例，如果指针包含空值（零值），则假定它不指向任何东西。
 *
 * 常量指针和指向常量的指针的区别：
 * 1. const char* str: 将 str 声明为指向 const char 的指针。这意味着这个指针指向的数据是不变的，可以修改指针，但任何修改数据的尝试都会引发编译错误。
 *      a. str++; 有效的，修改指针，而不是指向的数据。
 *      b. *str = 'a'; 无效的，尝试修改指向的数据。
 * 2. char* const str: 将 str 声明为指向 char 的 const 指针。这意味着这个指针是不变的，但指向的数据不是。指针无法修改，但我们可以使用指针修改数据。
 *      a. str++; 无效的，尝试修改常量指针变量
 *      b. *str = 'a'; 有效的，尝试修改指向的数据。在我们的例子中，这不会导致编译错误，但会导致运行时错误，因为字符串很可能会进入
 *         已编译二进制文件的只读部分。如果我们动态分配内存，这个语句就有意义，例如：char* const str = new char[5];
 * 3. const char* const str: 将 str 声明为指向 const char 的 const 指针。在这种情况下，我们既不能修改指针，也不能修改指向的数据。
 *      a. str++; 无效的，尝试修改常量指针变量
 *      b. *str = 'a'; 无效的，尝试修改指向的常量数据
 *
 *
 */

// C++中使用指针
#include <iostream>
#include <ctime>

using namespace std;

// 传递指针给函数
// 在写函数时应习惯性的先声明函数，然后定义函数
void getSeconds(unsigned long *ptr);

void getSeconds(unsigned long *ptr)
{
    *ptr = time(NULL);
    return;
}

int main(int argc, char const *argv[])
{
    int var = 20;   // 实际变量声明
    int *ip = NULL; // 指针变量声明
    unsigned long sec;

    cout << "指针 ip 的值是 " << ip << endl; // 输出 0x0

    ip = &var; // 在指针变量中存储 var 变量的地址

    cout << "变量 var 的地址: ";
    cout << &var << endl;

    cout << "变量 var 的值: ";
    cout << var << endl;

    cout << "指针变量中存储的地址: ";
    cout << ip << endl;

    cout << "访问指针变量中存储的值: ";
    cout << *ip << endl;

    getSeconds(&sec);

    cout << "秒数: " << sec << endl;

    return 0;
}
