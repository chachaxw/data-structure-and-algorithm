/**
 * @Author: Chacha 
 * @Date: 2018-12-13 22:10:30 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-12-20 22:01:21
 */

/**
 * Bubble Sorting 
 * Source: https://zh.wikipedia.org/wiki/冒泡排序
 */

#include <iostream>
using namespace std;
template<typename T> //整数或浮点数皆可使用,若要使用类(class)或结构体(struct)时必须重载大于(>)运算符

void bubbleSort(T arr[], int len)
{
    int i, j;
    
    for(i = 0; i < len; i++)
    {
        
        for(j = 0; j < len - 1 - i; j++)
        {
            
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
            
        }
        
    }
    
}

int main()
{
    int arr[] = { 2, 6, 4, 20, 9, 8 };
    int len = sizeof(arr)/sizeof(int);

    bubbleSort(arr, len);

    for (int i = 0; i < len; i++) {
        cout << arr[i] << ' ';
    }
	cout << endl;
}