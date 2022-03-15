/*
 * @Author: Chacha
 * @Date: 2022-03-15 14:19:00
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-15 15:02:31
 */

/**
 * 判断一个数是否为质数(素数)。
 * 定义：约数只有 1 和本身的整数成为质数，或称素数。
 * 注意：最小的质数是2。
 *
 */
#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

class Solution
{
private:
    /* data */
public:
    bool isPrime1(int num);

    bool isPrime2(int num);

    bool isPrime3(int num);
};

/**
 * 方法一：
 * 直观判断法(效率比较低)
 * 质数除了1和本身之外没有其他约数，所以判断n是否为质数，根据定义直接判断从2到n-1是否存在n的约数即可。
 *
 * 时间复杂度：O(n);
 *
 */
bool Solution::isPrime1(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
};

/**
 * 方法二：
 * 方法一的优化方法。
 * 对于每个数n，其实并不需要从2判断到n-1，我们知道，一个数若可以进行因数分解，那么分解时得到的两个数一定是一个小于等于sqrt(n)，
 * 一个大于等于sqrt(n)，据此，上述代码中并不需要遍历到n-1，遍历到sqrt(n)即可，因为若sqrt(n)左侧找不到约数，那么右侧也一定找不到约数。
 *
 * 时间复杂度：O(sqrt(n));
 *
 */
bool Solution::isPrime2(int num)
{
    int n = sqrt(num);
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
};

/**
 * 方法三：
 * 质数分布的规律：大于等于5的质数一定和6的倍数相邻。例如5和7，11和13,17和19等等；
 *
 * 1. 能被6整除的，肯定不是素数，故6x不是素数
 * 2. 能被2或3整除的，肯定不是素数，故6x+2、6x+3、6x+4也肯定不是素数
 * 3. 即6x+1、6x+5（等同6x-1）有可能为素数
 *
 * 步长设为6，每次只判断6前后的两个数即可。
 *
 */
bool Solution::isPrime3(int num)
{
    // 排除特殊情况
    if (num <= 3)
    {
        return num > 1;
    }

    // 不在6的两侧，肯定不是质数
    if (num % 6 != 1 && num % 6 != 5)
    {
        return 0;
    }

    int n = sqrt(num);
    for (int i = 5; i <= n; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return 0;
        }
    }

    return 1;
};

int main(int argc, char const *argv[])
{
    Solution s;
    int test_num = 100000;
    int t_start, t_stop;

    t_start = clock();

    for (int i = 2; i <= test_num; i++)
    {
        s.isPrime1(i);
    }

    t_stop = clock();

    cout << "方法一所需时间(ms)：" << t_stop - t_start << endl;

    t_start = clock();

    for (int i = 2; i <= test_num; i++)
    {
        s.isPrime2(i);
    }

    t_stop = clock();

    cout << "方法二所需时间(ms)：" << t_stop - t_start << endl;

    t_start = clock();

    for (int i = 2; i <= test_num; i++)
    {
        s.isPrime3(i);
    }

    t_stop = clock();

    cout << "方法三所需时间(ms)：" << t_stop - t_start << endl;

    return 0;
}
