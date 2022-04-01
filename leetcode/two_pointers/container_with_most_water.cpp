/*
 * @Author: Chacha
 * @Date: 2022-04-01 21:20:42
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-01 22:10:08
 */

/**
 *
 * 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。返回容器可以储存的最大水量。
 *
 * 输入：height = [1,8,6,2,5,4,8,3,7]
 * 输出：49
 * 解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 *
 * 示例 2：
 * 输入：height = [1,1]
 * 输出：1
 *
 * 提示：
 * 1. n == height.length
 * 2. 2 <= n <= 105
 * 3. 0 <= height[i] <= 104
 *
 */

#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

class Solution
{
private:
    /* data */
public:
    int maxArea(vector<int> &height);
};

/**
 * 双指针法
 * 设两指针i，j，指向的水槽板高度分别为 h[i]，h[j]，此状态下水槽面积S(i, j)。
 * 由于可容纳水的高度由两板中的 短板 决定，因此可得如下 面积公式 ：
 * S(i, j) = min(h[i], h[j]) × (j − i)
 *
 * 在每个状态下，无论长板或短板向中间收窄一格，都会导致水槽 底边宽度 −1 变短：
 * 1. 若向内移动短板，水槽的短板 min(h[i], h[j]) 可能变大，因此下个水槽的面积可能增大。
 * 2. 若向内移动长板，水槽的短板 min(h[i], h[j]) 不变或变小，因此下个水槽的面积 一定变小。
 *
 * 因此，初始化双指针分列水槽左右两端，循环每轮将短板向内移动一格，并更新面积最大值，直到两个指针相遇时跳出，即可获得最大面积
 *
 * 算法步骤：
 * 1. 初始化：双指针 i, j 分列水槽左右两端
 * 2. 循环收窄：直至双指针相遇时跳出
 *    a. 更新面积最大值 ans
 *    b. 选定两板高度中的短板，向中间收窄一格
 * 3. 返回面积最大值 ans 即可
 *
 */
int Solution::maxArea(vector<int> &height)
{
    int i = 0, j = height.size() - 1, ans = 0;

    while (i < j)
    {
        ans = height[i] < height[j] ? max(ans, (j - i) * height[i++]) : max(ans, (j - i) * height[j--]);
    }

    return ans;
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> height1 = {1, 1};

    cout
        << "输入：[1,8,6,2,5,4,8,3,7] 输出：" << s.maxArea(height) << endl;
    cout
        << "输入：[1, 1] 输出：" << s.maxArea(height1) << endl;

    return 0;
}
