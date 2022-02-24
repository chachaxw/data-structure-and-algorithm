/*
 * @Author: Chacha
 * @Date: 2022-02-24 17:47:37
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-02-24 19:13:14
 */

/**
 * 来源: https://www.runoob.com/cplusplus/cpp-overloading.html
 *
 * C++ 中的运算符重载
 * 重载运算符是带有特殊名称的函数，函数名是由关键字 operator 和 其后要重载的运算符符号构成，
 * 与其他函数一样，重载运算符有一个返回类型和一个参数列表。例如:
 * Box operator+(const Box&);
 * 声明加法运算符用于把两个 Box 对象相加，返回最终的 Box 对象。大多数的重载运算符可被定义为普通的
 * 非成员函数或者被定义为类成员函数。如果我们定义上面的函数为类的非成员函数，那么我们需要为每次操作传递两个参数。
 * 如下所示:
 * Box operator+(const Box&, const Box&);
 *
 * 可重载运算符:
 * 1. 双目运算符: + (加)，-(减)，*(乘)，/(除)，% (取模)
 * 2. 关系运算符: ==(等于)，!= (不等于)，< (小于)，> (大于)，<=(小于等于)，>=(大于等于)
 * 3. 逻辑运算符: ||(逻辑或)，&&(逻辑与)，!(逻辑非)
 * 4. 单目运算符: + (正)，-(负)，*(指针)，&(取地址)
 * 5. 自增自减运算符: ++(自增)，--(自减)
 * 6. 位运算符: | (按位或)，& (按位与)，~(按位取反)，^(按位异或),，<< (左移)，>>(右移)
 * 7. 赋值运算符: =, +=, -=, *=, /= , % = , &=, |=, ^=, <<=, >>=
 * 8. 空间申请与释放: new, delete, new[], delete[]
 * 9. 其他运算符: ()(函数调用), ->(成员访问), (逗号), [](下标)
 *
 * 不可重载运算符:
 * 1. 成员访问运算符: .
 * 2. 成员指针访问运算符: .*, ->*
 * 3. 域运算符: ::
 * 4. 长度运算符: sizeof
 * 5. 条件运算符: ?:
 * 6. 预处理符号: #
 *
 */

#include <iostream>

using namespace std;

class OperatorOverload
{
private:
    /* data */
    double width;
    double height;
    double length;

public:
    OperatorOverload();

    OperatorOverload(double, double, double);

    /**
     * 重载 + 运算符，用于把两个对象相加
     * 当重载的运算符函数是全局函数时，需要在类中将该函数声明为友元
     * 例如:
     * friend OperatorOverload operator+(const OperatorOverload &a, const OperatorOverload &b)
     * 因为其是全局函数，对应的参数个数为2个
     */
    OperatorOverload operator+(const OperatorOverload &o);

    // 重载 - 运算符，用于把两个对象相减
    OperatorOverload operator-(const OperatorOverload &o);

    void showInfo(char str[]);

    ~OperatorOverload();
};

OperatorOverload::OperatorOverload(){};

OperatorOverload::OperatorOverload(double w, double h, double l)
{
    width = w;
    height = h;
    length = l;
    cout << "构造函数" << endl;
};

OperatorOverload OperatorOverload::operator+(const OperatorOverload &o)
{
    OperatorOverload a;

    a.width = this->width + o.width;
    a.height = this->height + o.height;
    a.length = this->length + o.length;

    return a;
};

OperatorOverload OperatorOverload::operator-(const OperatorOverload &o)
{
    OperatorOverload a;

    a.width = this->width - o.width;
    a.height = this->height - o.height;
    a.length = this->length - o.length;

    return a;
};

void OperatorOverload::showInfo(char str[])
{
    cout << str << " width: " << width;
    cout << " height: " << height;
    cout << " length: " << length << endl;
};

OperatorOverload::~OperatorOverload()
{
    cout << "析构函数" << endl;
};

int main(int argc, char const *argv[])
{
    /* code */
    OperatorOverload obj1(1, 1, 1);
    OperatorOverload obj2(2, 2, 2);
    OperatorOverload obj3;
    OperatorOverload obj4;

    obj3 = obj1 + obj2;
    obj4 = obj3 - obj1;

    obj1.showInfo("obj1");
    obj2.showInfo("obj2");
    obj3.showInfo("obj3");
    obj4.showInfo("obj4");

    return 0;
}
