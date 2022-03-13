/**
 * @Author: Chacha
 * @Date: 2018-11-24 12:10:01
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-03-13 17:05:57
 */

/**
 * 1. 两数之和
 *
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回它们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 *
 * 示例:
 *   给定 nums = [2, 7, 11, 15], target = 9,
 *   因为 nums[0] + nums[1] = 2 + 7 = 9,
 *   返回 [0, 1].
 *
 * 来源：https://leetcode-cn.com/problems/two-sum/
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 方法一
 * 暴力枚举，枚举数组中的每一个数 x，寻找数组中是否存在 target - x。当我们使用遍历整个数组的方式寻找target - x时，
 * 需要注意到每一个位于 x 之前到元素都已经和 x 匹配过。而每一个元素不能被使用两次，
 * 所以我们只需要在 x 后面的元素中寻找 target - x。
 *
 * 复杂度：
 * 时间复杂度：O(N^2)，其中 N 是数组中的元素数量。最坏情况下数组中任意两个数都要被匹配一次。
 * 空间复杂度：O(1)
 *
 */
vector<int> twoSum1(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> result(0);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                cout << "i " << i << endl;
                cout << "j " << j << endl;
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }

    return result;
}

/**
 * 方法二
 * 哈希表，方法一的时间复杂度较高的原因是寻找 target - x 的时间复杂度过高，
 * 所以我们可以使用哈希表将 寻找 target - x 的时间复杂度从 O(N^2) 降低到 O(1)。
 * 我们创建一个哈希表，对于每一个 x， 我们首先查询哈希表中是否存在 target - x，然后将 x 插入到哈希表中，
 * 即保证不会让 x 和自己匹配。
 *
 * 复杂度：
 * 时间复杂度：O(N)，其中 N 是数组正宗到元素数量。对于每一个元素 x，我们可以 O(1) 地寻找 target - x。
 * 空间复杂度：O(N)，主要为哈希表的开销。
 *
 */
vector<int> twoSum2(vector<int> &nums, int target)
{
    // Key is the number and value is its index in the vector.
    unordered_map<int, int> hash;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++)
    {
        int number = target - nums[i];

        // if number is found in map, return them
        if (hash.find(number) != hash.end())
        {
            result.push_back(hash[number]);
            result.push_back(i);
            return result;
        }

        hash[nums[i]] = i;
    }

    return result;
}

void printVector(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%3d", vec[i]);
    }
    cout << endl;
}

int main()
{
    /* code */
    int arr[] = {2, 7, 11, 15};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    vector<int> result = twoSum1(nums, 9);

    printVector(result);
}
