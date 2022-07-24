/*
 * @Author: Chacha
 * @Date: 2022-07-24 22:29:36
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-07-24 23:08:35
 */

/**
 * 来源：https://leetcode.cn/problems/squares-of-a-sorted-array/
 *
 * 977. 有序数组的平方
 *
 * 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 *
 * 示例 1：
 * 输入：nums = [-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 解释：平方后，数组变为 [16,1,0,9,100]，排序后，数组变为 [0,1,9,16,100]
 *
 * 示例 2：
 * 输入：nums = [-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 *
 * 提示：
 * 1. 1 <= tokens.length <= 10^4
 * 2. -10^4 <= nums[i] <= 10^4
 * 3. nums 已按 非递减顺序 排序
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
    vector<int> sortSquares(vector<int> &nums);
};

/**
 * 方法：双指针法
 *
 * 数组其实是有序的，只不过负数平方之后可能成为最大数了，那么数组平方的最大值就在数组的两端，不是最左边就是最右边，不可能是中间。
 * 此时可以考虑双指针法了，i指向起始位置，j指向终止位置。定义一个新数组result，和A数组一样的大小，让k指向result数组终止位置。
 * 如果A[i] * A[i] < A[j] * A[j] 那么result[k--] = A[j] * A[j];
 * 如果A[i] * A[i] >= A[j] * A[j] 那么result[k--] = A[i] * A[i];
 *
 */
vector<int> Solution::sortSquares(vector<int> &nums)
{
    int k = nums.size() - 1;
    vector<int> result(nums.size(), 0);

    for (int i = 0, j = nums.size() - 1; i <= j;)
    {
        // 注意这里要i <= j，因为最后要处理两个元素
        if (nums[i] * nums[i] < nums[j] * nums[j])
        {
            result[k--] = nums[j] * nums[j];
            j--;
        }
        else
        {
            result[k--] = nums[i] * nums[i];
            i++;
        }
    }

    return result;
}

void printVector(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%3d ", vec[i]);
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> _nums = s.sortSquares(nums);

    cout << "nums = [-4, -1, 0, 3, 10], 运算结果为: " << endl;

    printVector(_nums);

    return 0;
}
