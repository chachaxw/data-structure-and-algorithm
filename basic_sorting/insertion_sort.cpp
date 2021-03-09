/**
 * @Author: Chacha
 * @Date: 2018-12-20 22:10:30
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-03-09 11:17:34
 */

#include <iostream>
using namespace std;

template <typename T> //整数或浮点数皆可使用,若要使用类(class)或结构体(struct)时必须重载大于(>)运算符

/**
 * Insertion Sorting(插入排序)
 * Source: https://zh.wikipedia.org/wiki/插入排序
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 *
 * 核心：通过构建有序序列，对于未排序序列，从后向前扫描(对于单向链表则只能从前往后遍历)，找到相应位置并插入。
 * 实现上通常使用in-place排序(需用到O(1)的额外空间)。
 *
 * 排序步骤：
 * 1. 从第一个元素开始，该元素可认为已排序
 * 2. 取下一个元素，对已排序数组从后往前扫描
 * 3. 若从排序数组中取出的元素大于新元素，则移至下一位置
 * 4. 重复步骤3，直至找到已排序元素小于或等于新元素的位置
 * 5. 插入新元素至该位置
 * 6. 重复2~5
 *
 */
void insertionSort(T arr[], int len)
{

    for (int i = 1; i < len; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/**
 * Shell Sorting(希尔排序)
 * Source: https://zh.wikipedia.org/wiki/希尔排序
 *
 * 核心：基于插入排序，使数组中任意间隔为h的元素都是有序的，即将全部元素分为h个区域使用插入排序。
 * 其实现可类似于插入排序但使用不同增量。更高效的原因是它权衡了子数组的规模和有序性。
 */
template <typename T>
void shellSort(T arr[], int len)
{
    int gap, i, j;
    T temp;

    for (gap = len >> 1; gap > 0; gap >>= 1)
    {

        for (i = gap; i < len; i++)
        {
            temp = arr[i];

            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
            {
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = temp;
        }
    }
}

int main()
{
    int arr[] = {2, 6, 4, 20, 9, 8};
    int len = sizeof(arr) / sizeof(int);

    // insertionSort(arr, len);
    shellSort(arr, len);

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
