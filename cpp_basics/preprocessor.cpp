/*
 * @Author: Chacha
 * @Date: 2022-02-28 16:35:56
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-02-28 17:23:35
 */

/**
 * 来源：https://www.runoob.com/cplusplus/cpp-preprocessor.html
 *
 * C++ 预处理器
 * 预处理器是一些指令，指示编译器在实际编译之前所需完成的预处理。所有的预处理器指令都是以井号（#）开头，
 * 只有空格字符可以出现在预处理指令之前。预处理指令不是 C++ 语句，所以它们不会以分号（;）结尾。
 *
 * C++ 提供了下表所示的一些预定义宏：
 * 1. __LINE__，这会在程序编译时包含当前行号。
 * 2. __FILE__，这会在程序编译时包含当前文件名。
 * 3. __DATE__，会包含一个形式为 month/day/year 的字符串，它表示把源文件转换为目标代码的日期。
 * 4. __TIME__，会包含一个形式为 hour:minute:second 的字符串，它表示程序被编译的时间。
 *
 */

#include <iostream>

using namespace std;

/**
 * #define 预处理
 *
 * #define 预处理指令用于创建符号常量。该符号常量通常称为宏，指令的一般形式是：
 * #define macro-name replacement-text
 *
 * 当这一行代码出现在一个文件中时，在该文件中后续出现的所有宏都将会在程序编译之前被替换为 replacement-text。
 */
#define PI 3.14159

/**
 * 参数宏
 *
 * 可以使用 #define 来定义一个带有参数的宏，如下所示：
 */
#define MIN(a, b) (a < b ? a : b)

/**
 * 条件编译
 *
 * 有几个指令可以用来有选择地对部分程序源代码进行编译。这个过程被称为条件编译。
 * 条件预处理器的结构与 if 选择结构很像。
 *
 * 您可以只在调试时进行编译，调试开关可以使用一个宏来实现，如下所示：
 */
#ifdef DEBUG
cout << "Debug code" << endl;
#endif // DEBUG

int main(int argc, char const *argv[])
{
    cout << "PI: " << PI << endl;

    int a = 10;
    int b = 20;

    cout << "较小的值为: " << MIN(a, b) << endl;

    cout << "__LINE__ : " << __LINE__ << endl;
    cout << "__FILE__ : " << __FILE__ << endl;
    cout << "__DATE__ : " << __DATE__ << endl;
    cout << "__TIME__ : " << __TIME__ << endl;

    return 0;
}
