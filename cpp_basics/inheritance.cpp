/*
 * @Author: Chacha
 * @Date: 2022-02-25 17:02:00
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-02-25 18:33:21
 */

/**
 * 来源: https://www.runoob.com/cplusplus/cpp-inheritance.html
 *
 * C++ 继承
 * 当创建一个类时，您不需要重新编写新的数据成员和成员函数，只需指定新建的类继承了一个已有的类的成员即可。这个已有的类称为基类，新建的类称为派生类。
 *
 * 基类 & 派生类
 * 一个类可以派生多个类，这意味着，它可以从多个基类继承数据和函数。定义一个派生类，定义一个派生类，
 * 我们使用一个类派生列表来指定基类。类派生列表以一个或多个基类命名，形式如下：
 * class derived-class: access-specifier base-class
 *
 * 其中，访问修饰符 access-specifier 是public、protected或private其中一个，base-class 是之前定义过的某个类的名称。
 * 如果未使用访问修饰符 access-specifier，则默认为 private。
 *
 * 访问控制和继承
 * 派生类可以访问基类中所有的非私有成员。因此基类成员如果不想被派生类的成员函数访问，则应在基类中声明为private。
 * 我们可以根据访问权限总结出不同的访问类型，如下所示：
 * ----- 访问 ----- public ----- protected ----- private -----
 * |   同一个类  ｜    是     ｜      是       ｜      是       ｜
 * |    派生类   ｜    是     ｜      是       ｜      否       ｜
 * |   外部的类  ｜    是     ｜      否       ｜      否      ｜
 * -----------------------------------------------------------
 *
 * 一个派生类继承了所有的基类方法，但下列情况除外：
 * 1. 基类的构造函数、析构函数和拷贝构造函数
 * 2. 基类的重载运算符
 * 3. 基类的友元函数
 *
 * 我们几乎不使用 protected 或 private 继承，通常使用 public 继承。当使用不同类型的继承时，遵循以下几个规则：
 * 1. 公有继承（public）：当一个类派生自公有基类时，基类的公有成员也是派生类的公有成员，基类的保护成员也是派生类的保护成员，
 *    基类的私有成员不能直接被派生类访问，但是可以通过调用基类的公有和保护成员来访问。
 * 2. 保护继承（protected）： 当一个类派生自保护基类时，基类的公有和保护成员将成为派生类的保护成员。
 * 3. 私有继承（private）：当一个类派生自私有基类时，基类的公有和保护成员将成为派生类的私有成员。
 *
 * 多继承
 * 多继承即一个子类可以有多个父类，它继承了多个父类的特性。
 * C++ 类可以从多个类继承成员，语法如下：
 * class <派生类名>:<继承方式1><基类名1>,<继承方式2><基类名2>,
 * {
 *      <派生类类体>
 * };
 *
 * 多继承(环状继承),A->D, B->D, C->(A，B)，例如：
 * class D {}
 * class A: public D {}
 * class B: public D {}
 * class C: public A, public B {};
 * 这个继承会使D创建两个对象，要解决上面的问题就要用虚拟继承格式。
 * 虚拟继承：class 类名: virtual 继承方式 父类名
 * class D {}
 * class A: virtual public D {}
 * class B: virtual public D {}
 * class C: public A, public B {};
 *
 */

#include <iostream>

using namespace std;

// 基类 Shape
class Shape
{
protected:
    int width;
    int height;

public:
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }
};

// 基类 PaintCost
class PaintCost
{
public:
    int getCost(int area)
    {
        return area * 70;
    }
};

// 派生类多继承
class Rectangle : public Shape, public PaintCost
{
public:
    int getArea()
    {
        return (width * height);
    }
};

int main(void)
{
    Rectangle Rect;
    int area;

    Rect.setWidth(5);
    Rect.setHeight(7);

    area = Rect.getArea();

    // 输出对象的面积
    cout << "总面积: " << Rect.getArea() << endl;

    // 输出总花费
    cout << "总花费: $" << Rect.getCost(area) << endl;

    return 0;
}
