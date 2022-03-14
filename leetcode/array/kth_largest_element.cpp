/*
 * @Author: Chacha
 * @Date: 2022-03-13 16:25:15
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-14 14:04:03
 */

/**
 * 来源：https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 *
 * 215. 数组中的第K个最大元素
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。请注意，
 * 你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 *
 * 1 <= k <= nums.length <= 104
 * -104 <= nums[i] <= 104
 *
 * 示例 1：
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 *
 * 示例 2；
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findKthLargest1(vector<int> &nums, int k);

    int findKthLargest2(vector<int> &nums, int k);

    int findKthLargest3(vector<int> &nums, int k);

    int partition(vector<int> &nums, int left, int right);

    void maxHeapify(vector<int> &nums, int i, int heap_size);

    void buildMaxHeap(vector<int> &nums, int heap_size);
};

/**
 * 方法一：暴力解法
 * 将数组升序排列之后，找到下标为 size - k 的目标元素即为结果。
 *
 * 时间复杂度：O(n*log n)，n是数组的长度
 * 空间复杂度：O(log n)
 *
 */
int Solution::findKthLargest1(vector<int> &nums, int k)
{
    int size = nums.size();
    sort(begin(nums), end(nums));
    return nums[size - k];
}

/**
 * 方法二：减而治之（逐渐缩小问题规模）
 * 注意：随机化切分元素。快速排序虽然快，但是在遇到特殊测试用例（顺序数组或者逆序数组）的时候，
 * 递归树会退化成链表，时间复杂度会变成 O(n^2)。
 * 在学习「快速排序」的时候，会学到 partition(切分)，通过 partition 操作使得：对于某个下标 j，nums[j] 已经排定，
 * 即 nums[j] 经过 partition(切分) 操作以后，会放置在它最终应该放置的位置。而且：
 * 1. nums[left] 到 nums[j-1] 中的所有元素都不大于 nums[j]
 * 2. nums[j + 1] 到 nums[right] 中的所有元素都不小于 nums[j]。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(log n)
 *
 */
int Solution::findKthLargest2(vector<int> &nums, int k)
{
    int size = nums.size();
    int left = 0;
    int right = size - 1;
    // 转换一下，第 k 大元素的下标是 len - k
    int target = size - k;

    while (true)
    {
        int index = partition(nums, left, right);

        if (index == target)
        {
            return nums[index];
        }
        else if (index < target)
        {
            left = index + 1;
        }
        else
        {
            right = index - 1;
        }
    }
}

/**
 * 对数组 nums 的子区间 [left..right] 执行 partition 操作，返回 nums[left] 排序以后应该在的位置
 * 在遍历过程中保持循环不变量的定义：
 * nums[left + 1..j] < nums[left]
 * nums[j..i] >= nums[left]
 */
int Solution::partition(vector<int> &nums, int left, int right)
{
    int pivot = nums[left];
    int j = left;

    for (int i = left + 1; i <= right; i++)
    {
        if (nums[i] < pivot)
        {
            // j 的初值为 left，先右移，再交换，小于 pivot 的元素都被交换到前面
            j++;
            swap(nums[j], nums[i]);
        }
    }

    // 在之前的遍历中，满足 nums[left+1]...nums[j] < pivot，并且 nums[j]...nums[i] >= pivot。
    // 交换之后，nums[left]...nums[j-1] < pivot，nums[j] = pivot，nums[j+1]...nums[i] >= pivot。
    swap(nums[j], nums[left]);
    return j;
};

/**
 * 方法三：堆(优先队列)
 * 可以用堆排序来解决这个问题-建立一个大根堆，做 k - 1 次 删除操作后，堆顶的元素就是我们要找的答案。
 * C++ 中可以直接用 priority_queue 来创建大根堆，但这里我们自己实现一个大根堆方法来创建大根堆。
 *
 * 时间复杂度：O(n*log n)，n是数组的长度
 * 空间复杂度：O(log n)
 *
 */
int Solution::findKthLargest3(vector<int> &nums, int k)
{
    int heap_size = nums.size();
    buildMaxHeap(nums, heap_size);

    for (int i = nums.size() - 1; i >= nums.size() - k + 1; i--)
    {
        swap(nums[0], nums[i]);
        heap_size--;
        maxHeapify(nums, 0, heap_size);
    }

    return nums[0];
};

void Solution::maxHeapify(vector<int> &nums, int i, int heap_size)
{
    int l = i * 2 + 1, r = i * 2 + 2, largest = i;

    if (l < heap_size && nums[l] > nums[largest])
    {
        largest = l;
    }

    if (r < heap_size && nums[r] > nums[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(nums[i], nums[largest]);
        maxHeapify(nums, largest, heap_size);
    }
}

void Solution::buildMaxHeap(vector<int> &nums, int heap_size)
{
    for (int i = heap_size / 2; i >= 0; i--)
    {
        maxHeapify(nums, i, heap_size);
    }
}

int main(int argc, char const *argv[])
{
    Solution s;
    int arr[] = {3, 2, 1, 5, 6, 4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    cout << "数组 nums 中第1个最大元素: " << s.findKthLargest1(nums, 1) << endl;
    cout << "数组 nums 中第2个最大元素: " << s.findKthLargest1(nums, 2) << endl;

    cout << "数组 nums 中第1个最大元素: " << s.findKthLargest2(nums, 1) << endl;
    cout << "数组 nums 中第2个最大元素: " << s.findKthLargest2(nums, 2) << endl;

    cout << "数组 nums 中第1个最大元素: " << s.findKthLargest3(nums, 1) << endl;
    cout << "数组 nums 中第2个最大元素: " << s.findKthLargest3(nums, 2) << endl;

    return 0;
}
