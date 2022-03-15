/*
 * @Author: Chacha
 * @Date: 2022-03-15 15:30:56
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-15 21:37:20
 */

/**
 * 来源：https://leetcode-cn.com/problems/remove-element/
 *
 * 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
 * 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
 * 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 *
 * 示例 1：
 * 输入：nums = [3,2,2,3], val = 3
 * 输出：2, nums = [2,2]
 * 解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。
 *      例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = [2,2,0,0]，也会被视作正确答案。
 *
 * 示例 2：
 * 输入：nums = [0,1,2,2,3,0,4,2], val = 2
 * 输出：5, nums = [0,1,4,0,3]
 * 解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
 *      注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement1(vector<int> &nums, int val);

    int removeElement2(vector<int> &nums, int val);
};

/**
 * 方法一：暴力解法
 * 暴力的解法就是两层for循环，一个for循环遍历数组元素 ，第二个for循环更新数组。
 *
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 *
 */
int Solution::removeElement1(vector<int> &nums, int val)
{
    int size = nums.size();

    for (int i = 0; i < size; i++)
    {

        if (nums[i] == val)
        {
            // 发现需要移除的元素，就将数组集体向前移动一位
            for (int j = i + 1; j < size; j++)
            {
                nums[j - 1] = nums[j];
            }
            i--;    // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
            size--; // 此时数组的大小-1
        }
    }

    return size;
}

/**
 * 方法二：双指针法
 * 双指针法（快慢指针法）：通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 *
 */
int Solution::removeElement2(vector<int> &nums, int val)
{
    int i = 0;

    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != val)
        {
            nums[i++] = nums[j];
        }
    }
    return i;
}

void printVector(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%3d", vec[i]);
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    Solution s;
    int arr[] = {0, 1, 2, 2, 3, 0, 4, 2};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    cout << "Remove element 2, result is " << s.removeElement1(nums, 2) << endl; // Remove element 2, result is 5

    printVector(nums);

    cout << "Remove element 3, result is " << s.removeElement2(nums, 3) << endl; // Remove element 3, result is 7

    printVector(nums);

    return 0;
}
