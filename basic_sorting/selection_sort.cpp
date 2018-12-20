/**
 * @Author: Chacha 
 * @Date: 2018-12-20 22:00:30 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-12-20 22:39:02
 */

/**
 * Selection Sorting 
 * Source: https://zh.wikipedia.org/wiki/选择排序
 */

#include <iostream>
#include <vector>
using namespace std;
template<typename T> //整数或浮点数皆可使用,若要使用类(class)或结构体(struct)时必须重载大于(>)运算符

void selectionSort(vector<T>& arr)
{
    int len = arr.size();

    for(int i = 0; i < len - 1; i++)
    {
        int min = i;
        
        for(int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }

}

int main()
{
    int arr[] = { 2, 6, 4, 20, 9, 8 };
    vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));

    selectionSort(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ' ';
    }
	cout << endl;
}