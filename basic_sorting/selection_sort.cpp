/**
 * @Author: Chacha
 * @Date: 2018-12-20 22:00:30
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-03-09 14:23:30
 */

/**
 * Selection Sorting
 * Source: https://zh.wikipedia.org/wiki/选择排序
 *
 * 核心：不断地选择剩余元素中的最小者。
 *
 * 1. 找到数组中最小元素并将其和数组第一个元素交换位置。
 * 2. 在剩下的元素中找到最小元素并将其与数组第二个元素交还，直至整个数组排序。
 *
 * 性质
 * 1. 比较次数 = (n - 1) + (n - 2) + (n - 3) + ... + 2 + 1 ≈ n^2/2
 * 2. 交还次数 = N
 * 3. 运行时间与输入无关
 * 4. 数据移动最少
 */

#include <iostream>
#include <vector>
using namespace std;
template <typename T> //整数或浮点数皆可使用,若要使用类(class)或结构体(struct)时必须重载大于(>)运算符

void selectionSort(vector<T> &arr)
{
    int len = arr.size();

    for (int i = 0; i < len - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

int main()
{
    int arr[] = {2, 6, 4, 20, 9, 8};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    selectionSort(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }
    cout << endl;
}
