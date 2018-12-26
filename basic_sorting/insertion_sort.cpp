/**
 * @Author: Chacha 
 * @Date: 2018-12-20 22:10:30 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-12-26 23:41:11
 */

#include <iostream>
using namespace std;
template<typename T> //整数或浮点数皆可使用,若要使用类(class)或结构体(struct)时必须重载大于(>)运算符

/**
 * Insertion Sorting 
 * Source: https://zh.wikipedia.org/wiki/插入排序
 */
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

/**
 * Shell Sorting 
 * Source: https://zh.wikipedia.org/wiki/希尔排序
 */
void shellSort(int arr[], int len) {
    int gap, i, j;
    int temp;

    for(gap = len >> 1; gap >0; gap >>= 1) {
    
        for(i = gap;i < len; i++) {
            temp = arr[i];
            
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap) {
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = temp;
        }
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