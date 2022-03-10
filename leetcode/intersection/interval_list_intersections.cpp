/*
 * @Author: Chacha
 * @Date: 2022-03-09 19:13:12
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-10 16:43:02
 */

/**
 * 来源：https://leetcode-cn.com/problems/interval-list-intersections/
 *
 * 求区间列表的交集
 * 给定两个由一些 闭区间 组成的列表，firstList 和 secondList，其中 firstList[i] = [starti, endi]，
 * 而 secondList[j] = [startj, endj]。每个区间列表都是成对 不相交 的，并且 已经排序。返回这两个区间列表的交集。
 * 形式上，闭区间 [a, b]（其中 a <= b）表示实数 x 的集合，而 a <= x <= b 。两个闭区间的 交集 是一组实数，
 * 要么为空集，要么为闭区间。例如，[1, 3] 和 [2, 4] 的交集为 [2, 3]。
 *
 * 示例1：
 * firstList:    0----2       5----------10    13----------------------23  24--25
 * secondList:     1----------5     8--------12      15--------------------24  25--26
 * ans:            1--2       5     8----10          15----------------23  24  25
 *
 * 输入：firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
 * 输出：[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 *
 * 示例2：
 * 输入：firstList = [[1,3],[5,9]], secondList = []
 * 输出：[]
 *
 * 示例3：
 * 输入：firstList = [], secondList = [[4,8],[10,12]]
 * 输出：[]
 *
 * 示例4：
 * 输入：firstList = [[1,7]], secondList = [[3,10]]
 * 输出：[[3,7]]
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
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList);

    void print(vector<vector<int>> a);
};

/**
 * 方法：双指针法
 *
 * 因为两个列表里都为不相交且已经排序好的区间，可以用双指针逐个检查重合区域，对于两个区间 arr1 = [left1, right1]
 * arr2 = [left2, right2]
 *
 * 判断重合：
 * 1. 若两个区间arr1 与 arr2 相交，那么重合区域为 [max(left1, left2), min(right1, right2)]
 * 2. 若不相交，则 right1 < left2 或 right2 < left1，那么求得的重合区域 max(left1, left2) 的值会
 *    比min(right1, right2)大，可以通过比较两个值来判断是否重合。
 *
 * 移动指针：
 * 1. 假设 right1 < right2，因为区间列表为不相交且已经排序好的，则 arr1 不可能与 secondList中的 arr2以后的任何区间相交。
 *    所以每次优先移动当前区间尾段较小的指针(right2 < right1同理)
 * 2. 若 right1 == right2，因为列表各个区间不相交，arr1 与 arr2 都不可能与之后的区间有交集，可以移动任意一个
 *
 *
 * 时间复杂度：O(m+n)，其中 M N 分别是数组 A 和 B 的长度
 * 空间复杂度：O(m+n)
 *
 */
vector<vector<int>> Solution::intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
{
    int i = 0, j = 0;
    int m = firstList.size();
    int n = secondList.size();

    vector<vector<int>> s;

    while (i < m && j < n)
    {
        int start = max(firstList[i][0], secondList[j][0]);
        int end = min(firstList[i][1], secondList[j][1]);

        if (start <= end)
        {
            s.push_back({start, end});
        }

        if (firstList[i][1] < secondList[j][1])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return s;
};

void Solution::print(vector<vector<int>> a)
{
    vector<vector<int>>::iterator p1;
    vector<int>::iterator p2;

    for (p1 = a.begin(); p1 != a.end(); p1++)
    {
        for (p2 = p1->begin(); p2 != p1->end(); p2++)
        {
            cout << "[" << *p2 << "]";
        }
        cout << endl;
    }

    cout << endl;
}

int main(int argc, char const *argv[])
{
    Solution s;

    vector<vector<int>> a;
    vector<vector<int>> b;

    a[0] = vector<int>(0, 2);
    a[1] = vector<int>(5, 10);
    a[2] = vector<int>(13, 23);
    a[3] = vector<int>(24, 25);

    b[0] = vector<int>(1, 5);
    b[1] = vector<int>(8, 12);
    b[2] = vector<int>(15, 24);
    b[3] = vector<int>(25, 26);

    vector<vector<int>> result = s.intervalIntersection(a, b);

    cout << "a 和 b 区间列表的交集是: " << endl;

    s.print(result);

    return 0;
}
