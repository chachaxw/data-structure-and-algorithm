/*
 * @Author: Chacha
 * @Date: 2022-02-28 15:03:35
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-02-28 15:32:41
 */

/**
 * 来源：https://www.runoob.com/cplusplus/cpp-templates.html
 *
 * C++模板
 * 模板是泛型编程的基础，泛型编程即以一种独立于任何特定类型的方式编写代码。
 * 模板是创建范型类的蓝图或公式。库容器，比如迭代器和算法，都是范型编程的例子，它们都使用了模板的概念。
 * 每个容器都有一个单一的定义，比如 向量，我们可以定义许多不同类型的向量，比如 vector <int> 或 vector <string>。
 * 可以使用模板来定义函数和类，接下来让我们一起来看看如何使用。
 *
 * 函数模板
 * 模板函数定义的一般形式如下所示：
 * template <typename type> ret-type func-name(parameter list)
 * {
 *      // 函数主体
 * }
 * 在这里，type 是函数所使用的数据类型的占位符名称。这个名称可以在函数定义中使用。
 *
 * 类模板
 * 正如我们定义函数模板一样，我们也可以定义类模板。泛型类声明的一般形式如下所示：
 * template<class type> class class-name
 * {
 * }
 *
 *
 */

#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// 函数模板实例，返回两个数中的最大值：
template <typename T>
inline T const &Max(T const &a, T const &b)
{
    return a < b ? b : a;
}

// 类模板实例
template <class T>
class Stack
{
private:
    vector<T> elems;

public:
    void push(T const &); // 入栈
    void pop();           // 出栈
    T top() const;        // 返回栈顶元素

    bool empty() const
    { // 如果为空则返回真
        return elems.empty();
    }
};

template <class T>
void Stack<T>::push(T const &elem)
{
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::pop(): empty stack");
    }

    elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::top(): empty stack");
    }

    return elems.back();
}

int main(int argc, char const *argv[])
{
    try
    {
        // 模板函数调用
        int a = 1;
        int b = 2;
        cout << "Max(a, b): " << Max(a, b) << endl;

        double a1 = 1.1;
        double b1 = 2.2;
        cout << "Max(a1, b1): " << Max(a1, b1) << endl;

        string a2 = "Hello";
        string b2 = "World";
        cout << "Max(a2, b2): " << Max(a2, b2) << endl;

        // 模板类调用
        Stack<int> s;

        s.push(1);
        s.push(2);
        s.push(3);

        cout << "栈顶元素: " << s.top() << endl;

        s.pop();
        cout << "栈顶元素: " << s.top() << endl;
    }
    catch (const exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
