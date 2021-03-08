/*
 * @Author: Chacha
 * @Date: 2021-03-07 23:06:51
 * @Last Modified by:   Chacha
 * @Last Modified time: 2021-03-07 23:06:51
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * 散列表是一种非线性数据结构，通过利用Hash函数将指定的【键 key】映射至对应的【值 value】，以实现高效的元素查找
 */

int main()
{
    // 散列表例子
    unordered_map<string, int> dic;

    // 添加 key -> value 键值对
    dic["小力"] = 10001;
    dic["小特"] = 10002;
    dic["小扣"] = 10003;

    cout << dic["小力"] << endl;

    return 0;
}
