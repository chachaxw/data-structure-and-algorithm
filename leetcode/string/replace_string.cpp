/*
 * @Author: Chacha
 * @Date: 2021-03-26 16:12:33
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-03-26 18:04:33
 */

/**
 * 题目：
 * 请实现一个函数，把字符串 s 中的每个空格替换成 "%20"。
 *
 * 来源：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
 *
 * 示例：
 * 输入：s = "We are coder."
 * 输出："We%20are%20coder"
 *
 * 限制：
 * 0 <= s的长度 <= 10000
 */

/**
 * 题解：
 *
 * 来源：https://leetcode-cn.com/leetbook/read/illustration-of-algorithm/50c26h/
 *
 * 在 C++ 语言中， string 被设计成「可变」的类型（参考资料：https://stackoverflow.com/questions/28442719/are-c-strings-mutable-unlike-java-strings），
 * 因此可以在不新建字符串的情况下实现原地修改。由于需要将空格替换成 "%20"，字符串的总数增加，因此需要扩展原字符串的长度。
 * 计算公式为：新字符串长度 = 原字符串 + 2 * 空格个数
 *
 * 算法步骤：
 * 1. 初始化：空格数量 count，字符串 s 的长度 len；
 * 2. 统计空格数量：遍历 s，遇到空格就count++；
 * 3. 修改 s 长度：添加完 "%20"后的字符串长度应为 len + 2 * count；
 * 4. 倒序遍历修改：i 指向原字符串尾部元素，j 指向新字符串尾部元素；当 i = j 时跳出（代表左方已经没有空格，无需继续遍历）；
 *    a. 当 s[i] 不为空格时：执行 s[j] = s[i]
 *    b. 当 s[i] 为空格时：将字符串闭区间[j - 2, j] 的元素修改为 "%20"；由于修改了3个元素，因此需要 j -= 2；
 * 5. 返回值：已修改的字符串 s；
 *
 * 复杂度：
 * 时间复杂度 O(n)：遍历统计、遍历修改都使用 O(n) 时间
 * 空间复杂度 O(1)：因为是原地扩展 s 的长度，所以使用 O(1) 额外空间
 *
 */

#include <iostream>

using namespace std;

class Solution
{
private:
    /* data */
public:
    string replaceSpace(string s)
    {
        int count = 0, len = s.size();

        // 计算空格长度
        for (char c : s)
        {
            if (c == ' ')
            {
                count++;
            }
        }

        // 修改 s 的长度
        s.resize(len + 2 * count);

        // 倒序遍历修改字符串
        for (int i = len - 1, j = s.size() - 1; i < j; i--, j--)
        {
            // 当 s[i] 不为空格时
            if (s[i] != ' ')
            {
                s[j] = s[i];
            }
            else
            { // 当 s[i] 为空格时
                s[j - 2] = '%';
                s[j - 1] = '2';
                s[j] = '0';
                j -= 2;
            }
        }

        return s;
    }
};

int main(int argc, char const *argv[])
{
    string s = "We are coder";

    std::cout << Solution().replaceSpace(s) << std::endl;

    return 0;
}
