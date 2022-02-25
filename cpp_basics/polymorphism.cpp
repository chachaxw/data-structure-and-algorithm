/*
 * @Author: Chacha
 * @Date: 2022-02-25 15:07:41
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-02-25 16:31:28
 */

/**
 * 来源: https://www.runoob.com/cplusplus/cpp-polymorphism.html
 *
 * C++ 多态
 * 多态按字面意思就是多种形态。当类之间存在层次结构，并且类之间是通过继承关联时，就会用到多态。
 * C++ 多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数。
 *
 * C++支持两种多态性：编译时动态性，运行时多态性。
 * 1. 编译时多态性(静态多态)：通过重载函数实现，先期联编 early binding
 * 2. 运行时多态性(动态多态)：通过虚函数实现，滞后联编 late binding
 *
 * 虚函数
 * 是在基类中使用关键字 virtual 声明的函数。在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数。
 * 我们想要的是在程序中任意点可以根据所调用的对象类型来选择调用的函数，这种操作被称为动态联编，或后期绑定。
 *
 * 纯虚函数
 * 在基类中定义虚函数，以便在派生类中重新定义该函数更好地适用于对象，但是在基类中又不能对虚函数给出有意义的实现，这个时候就会用到纯虚函数。
 *
 * 虚函数注意事项：
 * 1. 只有类的成员函数才能声明为虚函数，虚函数仅适用于有继承关系的类对象。普通函数不能声明为虚函数
 * 2. 静态成员函数不能是虚函数，因为静态成员函数不受限于某个对象。
 * 3. 内联函数(inline)不能是虚函数，因为内联函数不能在运行中动态确定位置。
 * 4. 构造函数不能是虚函数。
 * 5. 析构函数可以是虚函数，而且建议声明为虚函数。
 *
 * 隐藏
 * 除了重载与覆盖（重写），C++还有隐藏。隐藏是指派生类的函数屏蔽了与其同名的基类函数。隐藏规则如下：
 * 1. 如果派生类的函数与基类的函数同名，但参数不同，此时，不论有无 virtual 关键字，基类的函数都将被隐藏（注意别与重载混淆，重载是在同一个类中发生）。
 * 2. 如果派生类的函数与基类函数同名，并且参数也相同，但是基类函数没有 virtual 关键字，此时，基类的函数被隐藏（注意别与覆盖混淆，覆盖有virtual关键字）。
 *
 */

// 下面的实例中，基类 Shape 被派生为两个类，如下所示：
#include <iostream>

using namespace std;

class Shape
{
protected:
    /* data */
    int width, height;

public:
    Shape(int a = 0, int b = 0);

    int area();

    virtual int area1();

    // 纯虚函数，= 0 告诉编译器，函数没有主体，函数的具体实现交给派生类
    virtual int area2() = 0;
};

Shape::Shape(int a, int b)
{
    width = a;
    height = b;
};

int Shape::area()
{
    cout << "形状类 area: " << endl;
    return 0;
}

int Shape::area1()
{
    cout << "形状类 area1: " << endl;
    return 0;
}

class Rectangle : public Shape
{
public:
    Rectangle(int a = 0, int b = 0) : Shape(a, b) {}

    int area()
    {
        cout << "矩形类 area:" << endl;
        return (width * height);
    }

    // 子类与基类函数同名，有virtual关键字，运行时多态
    virtual int area1()
    {
        cout << "矩形类 area1:" << endl;
        return (width * height);
    }

    virtual int area2()
    {
        cout << "矩形类纯虚函数具体实现 area2:" << endl;
        return (width * height);
    }
};

class Triangle : public Shape
{
public:
    Triangle(int a = 0, int b = 0) : Shape(a, b) {}

    int area()
    {
        cout << "三角形类 area:" << endl;
        return (width * height / 2);
    }

    // 子类与基类函数同名，有virtual关键字，运行时多态
    virtual int area1()
    {
        cout << "三角形类 area1:" << endl;
        return (width * height / 2);
    }

    virtual int area2()
    {
        cout << "三角形类纯虚函数具体实现 area2:" << endl;
        return (width * height);
    }
};

int main(int argc, char const *argv[])
{
    Shape *shape;
    Rectangle rec(10, 8);
    Triangle tri(10, 5);

    // 情况1，调用不带 virtual 关键字的 area 函数

    // 存储矩形的地址
    shape = &rec;
    // 调用矩形的求面积函数 area
    shape->area();

    // 存储三角形的地址
    shape = &tri;
    // 调用三角形的求面积函数 area
    shape->area();

    /**
     * 上述代码输出结果为:
     * 形状类 area:
     * 形状类 area:
     *
     * 调用函数 area() 被编译器设置为基类中的版本，这就是所谓的静态多态，或者静态联编，函数调用在程序执行前就准备好了。
     * 有时候这也被称为早绑定，因为 area() 函数在程序编译期间就已经设置好了。
     */

    //
    // 情况2，调用带 virtual 关键字的 area1 函数
    //

    // 存储矩形的地址
    shape = &rec;
    // 调用矩形的求面积函数 area1
    shape->area1();

    // 存储三角形的地址
    shape = &tri;
    // 调用三角形的求面积函数 area1
    shape->area1();

    /**
     * 上述代码输出结果为:
     * 矩形类 area1:
     * 三角形类 area1:
     *
     * 此时，编译器看的是指针的内容，而不是它的类型。因此，由于 tri 和 rec 类的对象的地址存储在 *shape 中，所以会调用各自的 area1() 函数。
     * 正如您所看到的，每个子类都有一个函数 area() 的独立实现。这就是多态的一般使用方式。有了多态，就可以有多个不同的类，
     * 都带有同一个名称但具有不同实现的函数，函数的参数甚至可以是相同的。
     */

    return 0;
}
