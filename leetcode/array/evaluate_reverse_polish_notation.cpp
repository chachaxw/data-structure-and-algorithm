/*
 * @Author: Chacha
 * @Date: 2022-04-24 16:01:51
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-24 17:04:37
 */

/**
 * 来源：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/solution/
 *
 * 150. 逆波兰表达式求值
 *
 * 根据 逆波兰表示法，求表达式的值。
 * 有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
 * 注意 两个整数之间的除法只保留整数部分。
 * 可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 *
 * 逆波兰表达式：
 * 逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面：
 * 1. 平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。
 * 2. 该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。
 *
 * 逆波兰表达式主要有以下两个优点：
 * 1. 去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。
 * 2. 适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中。
 *
 *
 * 示例 1：
 * 输入：tokens = ["2","1","+","3","*"]
 * 输出：9
 * 解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
 *
 * 示例 2：
 * 输入：tokens = ["4","13","5","/","+"]
 * 输出：6
 * 解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
 *
 * 示例 3：
 * 输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
 * 输出：22
 * 解释：该算式转化为常见的中缀算术表达式为：
 *      ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 *      = ((10 * (6 / (12 * -11))) + 17) + 5
 *      = ((10 * (6 / -132)) + 17) + 5
 *      = ((10 * 0) + 17) + 5
 *      = (0 + 17) + 5
 *      = 17 + 5
 *      = 22
 *
 *
 * 提示：
 * 1. 1 <= tokens.length <= 10^4
 * 2. tokens[i] 是一个算符（"+"、"-"、"*" 或 "/"），或是在范围 [-200, 200] 内的一个整数
 *
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens);

    bool isNumber(string &token)
    {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }
};

/**
 * 方法一：栈
 *
 * 逆波兰表达式严格遵循「从左到右」的运算。计算逆波兰表达式的值时，使用一个栈存储操作数，从左到右遍历逆波兰表达式，进行如下操作：
 * 1. 如果遇到操作数，则将操作数入栈；
 * 2. 如果遇到运算符，则将两个操作数出栈，其中先出栈的是右操作数，后出栈的是左操作数，使用运算符对两个操作数进行运算，将运算得到的新操作数入栈。
 *
 * 整个逆波兰表达式遍历完毕之后，栈内只有一个元素，该元素即为逆波兰表达式的值。
 *
 * 时间复杂度：O(n)，其中 n 是数组 tokens 的长度。需要遍历数组 tokens 一次，计算逆波兰表达式的值。
 * 空间复杂度：O(n)，其中 n 是数组 tokens 的长度。使用栈存储计算过程中的数，栈内元素个数不会超过逆波兰表达式的长度。
 *
 *
 * 题解：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/solution/ni-bo-lan-biao-da-shi-qiu-zhi-by-leetcod-wue9/
 *
 */
int Solution::evalRPN(vector<string> &tokens)
{
    stack<int> stk;
    int n = tokens.size();

    for (int i = 0; i < n; i++)
    {
        string &token = tokens[i];

        if (isNumber(token))
        {
            stk.push(atoi(token.c_str()));
        }
        else
        {
            int num2 = stk.top();
            stk.pop();

            int num1 = stk.top();
            stk.pop();

            switch (token[0])
            {
            case '+':
                stk.push(num1 + num2);
                break;

            case '-':
                stk.push(num1 - num2);
                break;

            case '*':
                stk.push(num1 * num2);
                break;

            case '/':
                stk.push(num1 / num2);
                break;

            default:
                break;
            }
        }
    }

    return stk.top();
};

int main(int argc, char const *argv[])
{
    Solution s;

    string str[] = {"2", "1", "1", "3", "3"};
    string str1[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    vector<string> tokens(str, str + 5);
    vector<string> tokens1(str1, str1 + 13);

    cout << "tokens = ['2', '1', '+', '3', '*'], 运算结果为: " << s.evalRPN(tokens) << endl;
    cout << "tokens = ['10', '6', '9', '3', '+', '-11', '*', '/', '*', '17', '+', '5', '+'], 运算结果为: " << s.evalRPN(tokens1) << endl;

    return 0;
}
