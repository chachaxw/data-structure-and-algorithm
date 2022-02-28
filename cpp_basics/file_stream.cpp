/*
 * @Author: Chacha
 * @Date: 2022-02-28 10:27:17
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-02-28 15:03:56
 */

/**
 * 来源: https://www.runoob.com/cplusplus/cpp-files-streams.html
 *
 * C++ 文件和流
 * iostream 标准库，它提供了 cin 和 cout 方法分别用于从标准输入读取流和向标准输出写入流。
 *
 * C++ 中另一个标准库 fstream，它定义了三个新的数据类型：
 * 1. ofstream, 该数据类型表示输出文件流，用于创建文件并向文件写入信息。
 * 2. ifstream, 该数据类型表示输入文件流，用于从文件读取信息。
 * 3. fstream, 该数据类型通常表示文件流，且同时具有ofstream 和 ifstream两种功能，这意味着它可以创建文件，向文件写入信息，从文件读取信息。
 *
 * 要在 C++ 中进行文件处理，必须在 C++ 源代码文件中包含头文件 <iostream> 和 <fstream>。
 *
 * 打开文件
 * 在从文件读取信息或者向文件写入信息之前，必须先打开文件。ofstream 和 fstream 对象都可以用来打开文件进行写操作，
 * 如果只需要打开文件进行读操作，则使用 ifstream 对象。
 * 下面是open() 函数标准语法，open()函数是fstream、ifstream 和 ofstream对象的一个成员。
 * void open(const char* filename, ios::openmode mode);
 * 在这里，open() 成员函数的第一参数指定要打开的文件的名称和位置，第二个参数定义文件被打开的模式。
 *
 * 模式标志
 * 1. ios::app, 追加模式。所有写入都追加到文件末尾
 * 2. ios::ate, 文件打开后定位到文件末尾。
 * 3. ios::in, 打开文件用与读取。
 * 4. ios::out, 打开文件用于写入。
 * 5. ios::trunc, 如果该文件已经存在，其内容将在打开文件之前被截断，即把文件长度设为0。
 *
 * 可以把以上两种或两种以上的模式结合使用。例如，如果想要以写入模式打开文件，并希望截断文件，以防文件已存在，那么可以使用下面的语法：
 * ofstream outfile;
 * outfile.open("file.dat", ios::out | ios::trunc);
 *
 * 类似地，如果想要打开一个文件用于读写，可以使用下面的语法：
 * ifstream afile;
 * afile.open('file.dat', ios::out | ios::in);
 *
 * 关闭文件
 * 当 C++ 程序终止时，它会自动关闭刷新所有流，释放所有分配的内存，并关闭所有打开的文件。但程序员应该养成一个好习惯，在程序终止前关闭所有打开的文件。
 * 下面是 close() 函数的标准语法，close() 函数是 fstream、ifstream 和 ofstream 对象的一个成员。
 * void close();
 *
 * 写入文件
 * 在 C++ 编程中，我们使用流插入运算符 (<<) 向文件写入信息，就像使用该运算符输出信息到屏幕上一样。
 * 唯一不同的是，在这里使用的是 ofstream 和 fstream 对象，而不是 cout 对象。
 *
 * 读取文件
 * 在 C++ 编程中，我们使用流提取运算符（ >> ）从文件读取信息，就像使用该运算符从键盘输入信息一样。
 * 唯一不同的是，在这里您使用的是 ifstream 或 fstream 对象，而不是 cin 对象。
 *
 */

// 读取&写入实例

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char data[100];

    // 以写模式打开文件
    ofstream outfile;
    outfile.open("./example.txt");

    cout << "写入文件" << endl;
    cout << "输入你的名字: ";
    cin.getline(data, 100);

    // 向文件写入用户输入的数据
    outfile << "name=" << data << endl;

    cout << "输入你的年龄: ";
    cin >> data;
    cin.ignore();

    // 再次向文件写入用户输入的数据
    outfile << "age=" << data << endl;

    // 关闭打开的文件
    outfile.close();

    // 以读模式打开文件
    ifstream infile;
    infile.open("./example.txt");

    cout << "从文件中读取内容" << endl;
    infile >> data;

    // 在屏幕上写入数据
    cout << data << endl;

    // 再次从文件读取数据，并显示它
    infile >> data;
    cout << data << endl;

    // 关闭打开的文件
    infile.close();

    return 0;
}
