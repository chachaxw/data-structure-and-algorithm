/*
 * @Author: Chacha
 * @Date: 2022-04-11 11:06:31
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-15 22:46:06
 */

/**
 * 来源：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/
 *
 * 452. 用最少数量的箭引爆气球
 *
 * 在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。
 * 由于它是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横坐标就足够了。开始坐标总是小于结束坐标。
 *
 * 一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend，
 * 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。弓箭一旦被射出之后，可以无限地前进。
 * 我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。
 *
 * 给你一个数组 points ，其中 points [i] = [xstart,xend] ，返回引爆所有气球所必须射出的最小弓箭数。
 *
 * 示例 1：
 * 输入：points = [[10,16],[2,8],[1,6],[7,12]]
 * 输出：2
 * 解释：对于该样例，x = 6 可以射爆 [2,8],[1,6] 两个气球，以及 x = 11 射爆另外两个气球
 *
 * 示例 2：
 * 输入：points = [[1,2],[3,4],[5,6],[7,8]]
 * 输出：4
 *
 * 示例 3：
 * 输入：points = [[1,2],[2,3],[3,4],[4,5]]
 * 输出：2
 *
 * 示例 4：
 * 输入：points = [[1,2]]
 * 输出：1
 *
 * 示例 5：
 * 输入：points = [[2,3],[2,3]]
 * 输出：1
 *
 * 提示：
 * 0 <= points.length <= 104
 * points[i].length == 2
 * -2^31 <= xstart < xend <= 2^31 - 1
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
    int findMinArrowShots(vector<vector<int>> &points);
};

/**
 * 排序 + 贪心
 *
 * 时间复杂度：O(NlogN)，其中 N 是数组 points 的长度。排序的时间复杂度为 O(NlogN)，
 *           对所有气球进行遍历并计算答案的时间复杂度为 O(N)，其在渐进意义下小于前者，因此可以忽略。
 * 空间复杂度：O(logN)，即为排序需要使用的栈空间。
 *
 */
int Solution::findMinArrowShots(vector<vector<int>> &points)
{
    if (points.empty())
    {
        return 0;
    }

    // 将 points 按照 y 值（右边界）进行升序排序
    // 比如 [[10,16],[2,8],[1,6],[7,12]] -> [[1,6],[2,8],[7,12],[10,16]]
    sort(points.begin(), points.end(), [](const vector<int> &u, const vector<int> &v)
         { return u[1] < v[1]; });

    int pos = points[0][1];
    int ans = 1;

    for (const vector<int> &balloon : points)
    {
        if (balloon[0] > pos)
        {
            pos = balloon[1];
            ++ans;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> a;
    vector<vector<int>> b;

    a[0] = vector<int>(10, 16);
    a[1] = vector<int>(2, 8);
    a[2] = vector<int>(1, 6);
    a[3] = vector<int>(7, 12);

    b[0] = vector<int>(1, 2);
    b[1] = vector<int>(2, 3);
    b[2] = vector<int>(3, 4);
    b[3] = vector<int>(4, 5);

    cout << "[[10,16],[2,8],[1,6],[7,12]] findMinArrowShots" << s.findMinArrowShots(a) << endl;
    cout << "[[1,2],[3,4],[5,6],[7,8]] findMinArrowShots" << s.findMinArrowShots(b) << endl;

    return 0;
}
