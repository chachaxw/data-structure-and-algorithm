/*
 * @Author: Chacha
 * @Date: 2022-04-15 22:47:36
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-15 23:27:18
 */

/**
 * 来源：https://leetcode-cn.com/problems/assign-cookies/
 *
 * 455. 分发饼干
 *
 * 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
 * 对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。
 * 如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。
 * 你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
 *
 * 示例 1:
 * 输入: g = [1,2,3], s = [1,1]
 * 输出: 1
 * 解释:
 * 你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。
 * 虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。所以你应该输出1。
 *
 * 示例 2:
 * 输入: g = [1,2], s = [1,2,3]
 * 输出: 2
 * 解释:
 * 你有两个孩子和三块小饼干，2个孩子的胃口值分别是1,2。
 * 你拥有的饼干数量和尺寸都足以让所有孩子满足。所以你应该输出2.
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    /* data */
public:
    int findContentChildren(vector<int> &g, vector<int> &s);
};

/**
 * 排序 + 贪心
 *
 * 为了满足更多的小孩，就不要造成饼干尺寸的浪费。
 * 大尺寸的饼干既可以满足胃口大的孩子也可以满足胃口小的孩子，那么就应该优先满足胃口大的。
 * 这里的局部最优就是大饼干喂给胃口大的，充分利用饼干尺寸喂饱一个，全局最优就是喂饱尽可能多的小孩。
 * 可以尝试使用贪心策略，先将饼干数组和小孩数组排序。然后从后向前遍历小孩数组，用大饼干优先满足胃口大的，并统计满足小孩数量。
 *
 * 饼干：   1    3    5    9
 * 小孩：   1    2    7    10
 *
 * 这个例子可以看出饼干9只有喂给胃口为7的小孩，这样才是整体最优解，并想不出反例。
 *
 * 时间复杂度：O(NlogN)
 * 空间复杂度：O(1)
 *
 */
int Solution::findContentChildren(vector<int> &g, vector<int> &s)
{
    // 对 g 和 s 排序
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int index = s.size() - 1; // 饼干数组的下标
    int result = 0;

    for (int i = g.size() - 1; i >= 0; i--)
    {
        if (index >= 0 && s[index] >= g[i])
        {
            index--;
            result++;
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> c(4);
    vector<int> g(4);

    c[0] = 1;
    c[1] = 3;
    c[2] = 5;
    c[3] = 9;

    g[0] = 1;
    g[1] = 2;
    g[2] = 7;
    g[3] = 10;

    cout << "最大数值为：" << s.findContentChildren(c, g) << endl;

    return 0;
}
