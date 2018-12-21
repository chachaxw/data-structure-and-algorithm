/**
 * @Author: Chacha 
 * @Date: 2018-12-20 22:10:30 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-12-21 23:10:37
 */

/**
 * Bubble Sorting 
 * Source: https://zh.wikipedia.org/wiki/插入排序
 */

#include <iostream>
using namespace std;
template<typename T> //整数或浮点数皆可使用,若要使用类(class)或结构体(struct)时必须重载大于(>)运算符

void insertionSort(T arr[], int len) {
    
    for(int i = 1; i < len; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while((j >= 0) && (key < arr[j])){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    
}

int main() {
    int arr[] = { 2, 6, 4, 20, 9, 8 };
    int len = sizeof(arr)/sizeof(int);

    insertionSort(arr, len);

    for (int i = 0; i < len; i++) {
        cout << arr[i] << ' ';
    }
	cout << endl;
}